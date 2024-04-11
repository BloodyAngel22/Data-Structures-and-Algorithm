using System;
using System.Collections.Generic;
using System.Linq;

public class RTree
{
	class Node
	{
		public List<Entry> Entries { get; set; }
		public List<Node> Children { get; set; }

		public Node()
		{
			Entries = new List<Entry>();
			Children = new List<Node>();
		}

		public bool IsLeaf => Children.Count == 0;
	}

	public class Entry
	{
		public Rectangle Mbr { get; set; }
		public object Data { get; set; }
	}

	public class Rectangle
	{
		public double X { get; set; }
		public double Y { get; set; }
		public double Width { get; set; }
		public double Height { get; set; }

		public Rectangle(double x, double y, double width, double height)
		{
			X = x;
			Y = y;
			Width = width;
			Height = height;
		}

		public bool Intersects(Rectangle other)
		{
			return !(X + Width < other.X || other.X + other.Width < X || Y + Height < other.Y || other.Y + other.Height < Y);
		}

		public bool Contains(Rectangle other)
		{
			return X <= other.X && Y <= other.Y && X + Width >= other.X + other.Width && Y + Height >= other.Y + other.Height;
		}

		public double DistanceTo(Rectangle other)
		{
			double dx = Math.Max(0, Math.Max(other.X - (X + Width), X - (other.X + other.Width)));
			double dy = Math.Max(0, Math.Max(other.Y - (Y + Height), Y - (other.Y + other.Height)));
			return Math.Sqrt(dx * dx + dy * dy);
		}
	}

	private Node root;
	private int maxChildren;

	public RTree(int maxChildren)
	{
		root = new Node();
		this.maxChildren = maxChildren;
	}

	public void Insert(Rectangle mbr, object data)
	{
		Insert(new Entry { Mbr = mbr, Data = data }, root);
	}

	private void Insert(Entry entry, Node node)
	{
		if (node.IsLeaf)
		{
			node.Entries.Add(entry);
			if (node.Entries.Count > maxChildren)
			{
				SplitLeafNode(node);
			}
		}
		else
		{
			Node child = ChooseSubtree(entry.Mbr, node.Children);
			Insert(entry, child);
			AdjustTree(child, node);
		}
	}

	private void SplitLeafNode(Node node)
	{
		List<Entry> entries = node.Entries;
		Entry[] selectedEntries = PickSeeds(entries);

		Node newNode = new Node();
		newNode.Entries.Add(selectedEntries[1]);
		entries.Remove(selectedEntries[1]);

		Rectangle groupRect1 = selectedEntries[0].Mbr;
		Rectangle groupRect2 = selectedEntries[1].Mbr;

		while (entries.Any())
		{
			if ((groupRect1.Width >= groupRect2.Width && groupRect1.Height >= groupRect2.Height) || entries.Count == 1)
			{
				newNode.Entries.AddRange(entries);
				break;
			}
			else if ((groupRect2.Width >= groupRect1.Width && groupRect2.Height >= groupRect1.Height) || entries.Count == 1)
			{
				node.Entries.AddRange(entries);
				break;
			}

			Entry nextEntry = PickNext(entries, groupRect1, groupRect2);

			double areaIncrease1 = Enlargement(groupRect1, nextEntry.Mbr);
			double areaIncrease2 = Enlargement(groupRect2, nextEntry.Mbr);
			if (areaIncrease1 < areaIncrease2)
			{
				groupRect1 = Combine(groupRect1, nextEntry.Mbr);
				newNode.Entries.Add(nextEntry);
			}
			else if (areaIncrease2 < areaIncrease1)
			{
				groupRect2 = Combine(groupRect2, nextEntry.Mbr);
				entries.Add(nextEntry);
			}
			else
			{
				double area1 = groupRect1.Width * groupRect1.Height;
				double area2 = groupRect2.Width * groupRect2.Height;
				if (area1 < area2)
				{
					groupRect1 = Combine(groupRect1, nextEntry.Mbr);
					newNode.Entries.Add(nextEntry);
				}
				else
				{
					groupRect2 = Combine(groupRect2, nextEntry.Mbr);
					entries.Add(nextEntry);
				}
			}

			entries.Remove(nextEntry);
		}

		node.Entries.RemoveAll(e => newNode.Entries.Contains(e));
		node.Children.Add(newNode);
	}

	private Entry[] PickSeeds(List<Entry> entries)
	{
		Entry[] seeds = new Entry[2];
		double maxWaste = double.MinValue;

		for (int i = 0; i < entries.Count; i++)
		{
			for (int j = i + 1; j < entries.Count; j++)
			{
				Rectangle combinedRect = Combine(entries[i].Mbr, entries[j].Mbr);
				double waste = combinedRect.Width * combinedRect.Height - entries[i].Mbr.Width * entries[i].Mbr.Height - entries[j].Mbr.Width * entries[j].Mbr.Height;
				if (waste > maxWaste)
				{
					maxWaste = waste;
					seeds[0] = entries[i];
					seeds[1] = entries[j];
				}
			}
		}

		return seeds;
	}

	private Rectangle Combine(Rectangle rect1, Rectangle rect2)
	{
		double x1 = Math.Min(rect1.X, rect2.X);
		double y1 = Math.Min(rect1.Y, rect2.Y);
		double x2 = Math.Max(rect1.X + rect1.Width, rect2.X + rect2.Width);
		double y2 = Math.Max(rect1.Y + rect1.Height, rect2.Y + rect2.Height);
		return new Rectangle(x1, y1, x2 - x1, y2 - y1);
	}

	private double Enlargement(Rectangle rect, Rectangle newRect)
	{
		double area = rect.Width * rect.Height;
		double newArea = Combine(rect, newRect).Width * Combine(rect, newRect).Height;
		return newArea - area;
	}

	private Entry PickNext(List<Entry> entries, Rectangle groupRect1, Rectangle groupRect2)
	{
		Entry bestEntry = null;
		double maxDiff = double.MinValue;

		foreach (Entry entry in entries)
		{
			double diff = Math.Abs(Enlargement(groupRect1, entry.Mbr) - Enlargement(groupRect2, entry.Mbr));
			if (diff > maxDiff)
			{
				maxDiff = diff;
				bestEntry = entry;
			}
		}

		return bestEntry;
	}

	private Node ChooseSubtree(Rectangle mbr, List<Node> nodes)
	{
		Node bestNode = null;
		double minArea = double.MaxValue;

		foreach (Node node in nodes)
		{
			Rectangle combinedRect = Combine(mbr, node.Entries.Select(e => e.Mbr).Aggregate((r1, r2) => Combine(r1, r2)));
			double area = combinedRect.Width * combinedRect.Height;
			if (area < minArea)
			{
				minArea = area;
				bestNode = node;
			}
		}

		return bestNode;
	}

	private void AdjustTree(Node node, Node parentNode)
	{
		if (node.Entries.Count <= maxChildren)
		{
			return;
		}

		Node newNode = new Node();
		newNode.Entries.AddRange(node.Entries.GetRange(maxChildren / 2, node.Entries.Count - maxChildren / 2));
		node.Entries.RemoveRange(maxChildren / 2, node.Entries.Count - maxChildren / 2);

		if (parentNode == null)
		{
			parentNode = new Node();
			parentNode.Children.Add(node);
			root = parentNode;
		}

		parentNode.Children.Add(newNode);
		AdjustTree(newNode, parentNode);
	}

	public List<object> Search(Rectangle mbr)
	{
		List<object> result = new List<object>();
		Search(mbr, root, result);
		return result;
	}

	private void Search(Rectangle mbr, Node node, List<object> result)
	{
		foreach (Entry entry in node.Entries)
		{
			if (entry.Mbr.Intersects(mbr))
			{
				result.Add(entry.Data);
			}
		}

		foreach (Node child in node.Children)
		{
			if (child.Entries.Any(e => e.Mbr.Intersects(mbr)))
			{
				Search(mbr, child, result);
			}
		}
	}

	public List<object> SearchExact(Rectangle mbr)
	{
		List<object> result = new List<object>();
		SearchExact(mbr, root, result);
		return result;
	}

	private void SearchExact(Rectangle mbr, Node node, List<object> result)
	{
		foreach (Entry entry in node.Entries)
		{
			if (entry.Mbr.X == mbr.X && entry.Mbr.Y == mbr.Y && entry.Mbr.Width == mbr.Width && entry.Mbr.Height == mbr.Height)
			{
				result.Add(entry.Data);
			}
		}

		foreach (Node child in node.Children)
		{
			if (child.Entries.Any(e => e.Mbr.Intersects(mbr)))
			{
				SearchExact(mbr, child, result);
			}
		}
	}

	public List<object> SearchRange(Rectangle range)
	{
		List<object> result = new List<object>();
		SearchRange(range, root, result);
		return result;
	}

	private void SearchRange(Rectangle range, Node node, List<object> result)
	{
		foreach (Entry entry in node.Entries)
		{
			if (range.Contains(entry.Mbr))
			{
				result.Add(entry.Data);
			}
		}

		foreach (Node child in node.Children)
		{
			if (child.Entries.Any(e => e.Mbr.Intersects(range)))
			{
				SearchRange(range, child, result);
			}
		}
	}

	public object FindNearest(Rectangle point)
	{
		return FindNearest(point, root, double.MaxValue, null);
	}

	private object FindNearest(Rectangle point, Node node, double bestDistance, object bestEntry)
	{
		foreach (Entry entry in node.Entries)
		{
			double distance = entry.Mbr.DistanceTo(point);
			if (distance < bestDistance)
			{
				bestDistance = distance;
				bestEntry = entry.Data;
			}
		}

		foreach (Node child in node.Children)
		{
			double childDistance = child.Entries.Select(e => e.Mbr.DistanceTo(point)).Min();
			if (childDistance < bestDistance)
			{
				bestEntry = FindNearest(point, child, bestDistance, bestEntry);
				bestDistance = bestEntry != null ? point.DistanceTo(((Entry)bestEntry).Mbr) : double.MaxValue;
			}
		}

		return bestEntry;
	}
	public bool Delete(Rectangle mbr, object data)
	{
		bool deleted = Delete(root, mbr, data, null);
		if (deleted)
		{
			Console.WriteLine("Элемент успешно удален.");
		}
		else
		{
			Console.WriteLine("Элемент не найден или не удален.");
		}
		return deleted;
	}

	private bool Delete(Node node, Rectangle mbr, object data, Node parentNode)
	{
		if (node == null)
		{
			return false;
		}

		foreach (Entry entry in node.Entries)
		{
			if (entry.Mbr.X == mbr.X && entry.Mbr.Y == mbr.Y && entry.Mbr.Width == mbr.Width && entry.Mbr.Height == mbr.Height && entry.Data.Equals(data))
			{
				node.Entries.Remove(entry);
				if (parentNode != null)
				{
					AdjustTree(node, parentNode);
				}
				else if (node.Entries.Count == 0 && node.Children.Count == 1)
				{
					root = node.Children[0];
				}
				return true;
			}
		}

		foreach (Node child in node.Children)
		{
			if (Delete(child, mbr, data, node))
			{
				return true;
			}
		}
		return false;
	}

}

class Program
{
	static void Main(string[] args)
	{
		RTree rTree = new(10);

		rTree.Insert(new RTree.Rectangle(0, 0, 10, 10), "A");
		rTree.Insert(new RTree.Rectangle(5, 5, 10, 10), "B");
		rTree.Insert(new RTree.Rectangle(20, 20, 10, 10), "C");
		rTree.Insert(new RTree.Rectangle(4, 4, 10, 10), "D");
		rTree.Insert(new RTree.Rectangle(1, 1, 5, 5), "E");
		rTree.Insert(new RTree.Rectangle(30, 30, 5, 5), "F");
		rTree.Insert(new RTree.Rectangle(25, 25, 5, 5), "G");
		rTree.Insert(new RTree.Rectangle(10, 10, 5, 5), "H");
		rTree.Insert(new RTree.Rectangle(15, 15, 5, 5), "I");

		RTree.Rectangle queryRectangle = new RTree.Rectangle(3, 3, 8, 8);
		List<object> result = rTree.Search(queryRectangle);

		Console.WriteLine("Прямоугольники, пересекающиеся с запросом:");
		foreach (var entry in result)
		{
			Console.WriteLine(entry);
		}

		List<object> exactResult = rTree.SearchExact(new RTree.Rectangle(0, 0, 10, 10));

		Console.WriteLine("Прямоугольники, точно совпадающие с запросом:");
		foreach (var entry in exactResult)
		{
			Console.WriteLine(entry);
		}

		RTree.Rectangle range = new RTree.Rectangle(4, 4, 15, 15);
		List<object> rangeResult = rTree.SearchRange(range);

		Console.WriteLine("Прямоугольники в пределах диапазона:");
		foreach (var entry in rangeResult)
		{
			Console.WriteLine(entry);
		}

		RTree.Rectangle point = new RTree.Rectangle(25, 25, 0, 0);
		object nearest = rTree.FindNearest(point);

		Console.WriteLine("Ближайший прямоугольник к точке:");
		Console.WriteLine(nearest);

		rTree.Delete(new RTree.Rectangle(0, 0, 10, 10), "A");
		Console.WriteLine("Прямоугольники после удаления:");
		foreach (var entry in rTree.Search(new RTree.Rectangle(0, 0, 10, 10)))
		{
			Console.WriteLine(entry);
		}
	}
}
