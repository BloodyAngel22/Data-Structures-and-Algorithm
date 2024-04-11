using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace lab3._2
{
	public class Rectangle
	{
		public int MinX { get; set; }
		public int MinY { get; set; }
		public int MaxX { get; set; }
		public int MaxY { get; set; }

		public Rectangle(int minX, int minY, int maxX, int maxY)
		{
			MinX = minX;
			MinY = minY;
			MaxX = maxX;
			MaxY = maxY;
		}

		public bool Contains(Rectangle other)
		{
			return (other.MinX >= MinX && other.MaxX <= MaxX && other.MinY >= MinY && other.MaxY <= MaxY);
		}

		public bool Intersects(Rectangle other)
		{
			return !(this.MaxX < other.MinX || other.MaxX < this.MinX || this.MaxY < other.MinY || other.MaxY < this.MinY);
		}

		public int CalculateArea()
		{
			return (MaxX - MinX) * (MaxY - MinY);
		}
	}
}