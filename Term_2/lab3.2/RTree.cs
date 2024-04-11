using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace lab3._2
{
	public class RTree
	{
		private Node root;

		public RTree()
		{
			root = new Node();
		}

		public void Insert(int minX, int minY, int maxX, int maxY)
		{
			Rectangle rect = new Rectangle(minX, minY, maxX, maxY);
			Insert(root, rect);
		}

		private void Insert(Node node, Rectangle rect)
		{
			if (node.Rectangles.Count < 10) 
			{
				node.Rectangles.Add(rect);
				return;
			}

			Node minNode = ChooseSubtree(node, rect);
			Insert(minNode, rect);
		}

		private Node ChooseSubtree(Node node, Rectangle rect)
		{
			double minAreaIncrease = double.MaxValue;
			Node minNode = null;

			foreach (Node child in node.Children)
			{
				Rectangle newRect = ExpandRectangle(child.Rectangles[0], rect);
				double areaIncrease = CalculateArea(newRect) - CalculateArea(child.Rectangles[0]);
				if (areaIncrease < minAreaIncrease)
				{
					minAreaIncrease = areaIncrease;
					minNode = child;
				}
			}

			return minNode;
		}

		public void Remove(Rectangle rect)
		{
			Remove(root, rect);
		}

		private void Remove(Node node, Rectangle rect)
		{
			if (node == null)
				return;

			for (int i = 0; i < node.Rectangles.Count; i++)
			{
				if (node.Rectangles[i].MinX == rect.MinX && node.Rectangles[i].MinY == rect.MinY && node.Rectangles[i].MaxX == rect.MaxX && node.Rectangles[i].MaxY == rect.MaxY)
				{
					node.Rectangles.RemoveAt(i);
					return;
				}
			}

			foreach (Node child in node.Children)
			{
				if (rect.Intersects(child.Rectangles[0]))
				{
					Remove(child, rect);
					return;
				}
			}
		}

		public bool SearchExact(Rectangle rect)
		{
			return SearchExact(root, rect);
		}

		private bool SearchExact(Node node, Rectangle rect)
		{
			if (node == null)
				return false;

			foreach (Rectangle r in node.Rectangles)
			{
				if (r.MinX == rect.MinX && r.MinY == rect.MinY && r.MaxX == rect.MaxX && r.MaxY == rect.MaxY)
					return true;
			}

			foreach (Node child in node.Children)
			{
				if (rect.Intersects(child.Rectangles[0]))
				{
					bool result = SearchExact(child, rect);
					if (result == true)
						return true;
				}
			}

			return false;
		}

		public List<Rectangle> SearchRegion(Rectangle rect)
		{
			List<Rectangle> result = new List<Rectangle>();
			SearchRegion(root, rect, result);
			return result;
		}

		private void SearchRegion(Node node, Rectangle rect, List<Rectangle> result)
		{
			if (node == null)
				return;

			foreach (Rectangle r in node.Rectangles)
			{
				if (rect.Intersects(r))
					result.Add(r);
			}

			foreach (Node child in node.Children)
			{
				if (rect.Intersects(child.Rectangles[0]))
					SearchRegion(child, rect, result);
			}
		}

		public Rectangle SearchNearest(int x, int y)
		{
			Rectangle queryPoint = new Rectangle(x, y, x, y);
			return SearchNearest(root, queryPoint, double.MaxValue);
		}

		private Rectangle SearchNearest(Node node, Rectangle queryPoint, double bestDistance)
		{
			if (node == null)
				return null;

			Rectangle nearest = null;
			double nearestDistance = bestDistance;

			foreach (Rectangle r in node.Rectangles)
			{
				double distance = CalculateDistance(queryPoint, r);
				if (distance < nearestDistance)
				{
					nearest = r;
					nearestDistance = distance;
				}
			}

			foreach (Node child in node.Children)
			{
				double distance = CalculateDistance(queryPoint, child.Rectangles[0]);
				if (distance < nearestDistance)
				{
					Rectangle nearestInChild = SearchNearest(child, queryPoint, nearestDistance);
					if (nearestInChild != null)
					{
						nearest = nearestInChild;
						nearestDistance = distance;
					}
				}
			}

			return nearest;
		}

		private double CalculateDistance(Rectangle p1, Rectangle p2)
		{
			return Math.Sqrt(Math.Pow(p2.MinX - p1.MinX, 2) + Math.Pow(p2.MinY - p1.MinY, 2));
		}

		private Rectangle ExpandRectangle(Rectangle existingRect, Rectangle newRect)
		{
			int minX = Math.Min(existingRect.MinX, newRect.MinX);
			int minY = Math.Min(existingRect.MinY, newRect.MinY);
			int maxX = Math.Max(existingRect.MaxX, newRect.MaxX);
			int maxY = Math.Max(existingRect.MaxY, newRect.MaxY);
			return new Rectangle(minX, minY, maxX, maxY);
		}

		private int CalculateArea(Rectangle rect)
		{
			return (rect.MaxX - rect.MinX) * (rect.MaxY - rect.MinY);
		}
	}
}