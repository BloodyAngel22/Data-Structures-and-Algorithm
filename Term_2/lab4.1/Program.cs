public class Graph
{
	private Dictionary<int, List<int>> adjacencyList;

	public Graph()
	{
		adjacencyList = new Dictionary<int, List<int>>();
	}

	public void AddEdge(int v, int w)
	{
		if (!adjacencyList.ContainsKey(v))
		{
			adjacencyList[v] = new List<int>();
		}
		adjacencyList[v].Add(w);

		if (!adjacencyList.ContainsKey(w))
		{
			adjacencyList[w] = new List<int>();
		}
		adjacencyList[w].Add(v);
	}

	public int ShortestPath(int start, int end)
	{
		Queue<int> queue = new Queue<int>();
		HashSet<int> visited = new HashSet<int>();
		Dictionary<int, int> distance = new Dictionary<int, int>();

		queue.Enqueue(start);
		visited.Add(start);
		distance[start] = 0;

		while (queue.Count > 0)
		{
			int current = queue.Dequeue();

			if (current == end)
			{
				return distance[current];
			}

			foreach (int neighbor in adjacencyList[current])
			{
				if (!visited.Contains(neighbor))
				{
					visited.Add(neighbor);
					distance[neighbor] = distance[current] + 1;
					queue.Enqueue(neighbor);
				}
			}
		}

		return -1;
	}
}

class Program
{
	static void Main(string[] args)
	{
		Graph graph = new Graph();
		graph.AddEdge(1, 2);
		graph.AddEdge(1, 3);
		graph.AddEdge(2, 4);
		graph.AddEdge(3, 5);
		graph.AddEdge(4, 6);
		graph.AddEdge(5, 6);
		graph.AddEdge(7, 9);
		graph.AddEdge(1, 8);

		int startStudent = 4; 
		int endStudent = 8; 

		int weeks = graph.ShortestPath(startStudent, endStudent);
		if (weeks == -1)
		{
			Console.WriteLine("Студенты не могут познакомиться");
		}
		else
		{
			Console.WriteLine($"Студенты познакомятся через {weeks} недель");
		}
	}
}
