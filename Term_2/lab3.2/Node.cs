using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace lab3._2
{
	public class Node
	{
		public List<Rectangle> Rectangles { get; set; }
		public List<Node> Children { get; set; }
		public Node Parent { get; set; }

		public Node(Node parent = null)
		{
			Rectangles = new List<Rectangle>();
			Children = new List<Node>();
			Parent = parent;
		}
	}
}