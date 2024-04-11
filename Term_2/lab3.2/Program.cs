using lab3._2;

RTree rtree = new ();

rtree.Insert(0, 0, 2, 2);
rtree.Insert(1, 1, 3, 3);
rtree.Insert(3, 3, 5, 5);
rtree.Insert(7, 7, 10, 10);
rtree.Insert(2, 2, 5, 5);

Rectangle RectangleToRemove = new (1, 1, 3, 3);
System.Console.WriteLine("Remove");
System.Console.WriteLine(format: "{0} {1} {2} {3}", RectangleToRemove.MinX, RectangleToRemove.MinY, RectangleToRemove.MaxX, RectangleToRemove.MaxY);
rtree.Remove(RectangleToRemove);

Rectangle rect = new (0,0,2,2);
bool found = rtree.SearchExact(rect);
System.Console.WriteLine("Find");
System.Console.WriteLine(found);

Rectangle region = new (0, 0, 2, 2);
List<Rectangle> RectanglesInRegion = rtree.SearchRegion(region);
System.Console.WriteLine("Region");
foreach (var Rectangle in RectanglesInRegion)
{
	System.Console.WriteLine(format: "{0} {1} {2} {3}", Rectangle.MinX, Rectangle.MinY, Rectangle.MaxX, Rectangle.MaxY);	
}

Rectangle nearestNeighbor = rtree.SearchNearest(2, 4);
System.Console.WriteLine("NearestNeighbor");
System.Console.WriteLine(format: "{0} {1} {2} {3}", nearestNeighbor.MinX, nearestNeighbor.MinY, nearestNeighbor.MaxX, nearestNeighbor.MaxY);

