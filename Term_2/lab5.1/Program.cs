using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;

class Airport
{
	public string Name { get; }
	public Dictionary<Airport, int> Flights { get; } = new Dictionary<Airport, int>();

	public Airport(string name)
	{
		Name = name;
	}

	public void AddFlight(Airport destination, int cost)
	{
		Flights[destination] = cost;
	}
}

class Program
{
	static Dictionary<string, Airport> airports = new Dictionary<string, Airport>();

	static void Main(string[] args)
	{
		Airport a1 = new Airport("A");
		Airport a2 = new Airport("B");
		Airport a3 = new Airport("C");
		Airport a4 = new Airport("D");
		Airport a5 = new Airport("E");

		a1.AddFlight(a2, 100); 
		a1.AddFlight(a3, 400);
		a1.AddFlight(a4, 200);
		a1.AddFlight(a5, 750);

		a2.AddFlight(a3, 150);
		a2.AddFlight(a4, 450);
		a2.AddFlight(a5, 350);

		a3.AddFlight(a4, 300);
		a3.AddFlight(a5, 200);

		a4.AddFlight(a5, 500);

		airports.Add(a1.Name, a1);
		airports.Add(a2.Name, a2);
		airports.Add(a3.Name, a3);
		airports.Add(a4.Name, a4);
		airports.Add(a5.Name, a5);

		List<Airport> route = FindOptimalRoute(a1, a5);

		Console.WriteLine("Оптимальный маршрут:");
		foreach (var airport in route)
		{
			Console.WriteLine(airport.Name);
		}
		Console.WriteLine("Стоимость маршрута: " + GetSumOptimalRoute(route));
	}

	static List<Airport> FindOptimalRoute(Airport start, Airport end)
	{
		Dictionary<Airport, int> minCost = new Dictionary<Airport, int>();
		Dictionary<Airport, Airport> prevAirport = new Dictionary<Airport, Airport>();
		Queue<Airport> queue = new Queue<Airport>();

		foreach (var air in airports.Values)
		{
			minCost[air] = int.MaxValue;
			prevAirport[air] = null;
		}

		minCost[start] = 0;
		queue.Enqueue(start);

		while (queue.Count > 0)
		{
			Airport current = queue.Dequeue();

			foreach (var flight in current.Flights)
			{
				Airport destination = flight.Key;
				int cost = flight.Value;

				if (minCost[current] + cost < minCost[destination])
				{
					minCost[destination] = minCost[current] + cost;
					prevAirport[destination] = current;
					queue.Enqueue(destination);
				}
			}
		}

		List<Airport> route = new List<Airport>();
		Airport airport = end;

		while (airport != null)
		{
			route.Add(airport);
			airport = prevAirport[airport];
		}

		route.Reverse();
		return route;
	}
	static int GetSumOptimalRoute(List<Airport> route)
	{
		int sum = 0;
		for (int i = 0; i < route.Count - 1; i++)
		{
			sum += route[i].Flights[route[i + 1]];
		}
		return sum;
	}
}
