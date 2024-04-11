using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace lab2._1
{
	class HashTable
	{
		private HashItem[] carNumbers;
		private int curSize;
		private Random rnd = new(unchecked((int)(DateTime.Now.Ticks)));
		private bool IsFirst = false;

		public HashTable(int size)
		{
			carNumbers = new HashItem[size];
			curSize = 0;
		}

		public void Add(string value)
		{
			if (curSize >= carNumbers.Length )
			{
				System.Console.WriteLine("Overflow");
				return;
			}
			var key = GetHashCode(value);
			if (IsCopy(key, value))
			{
				System.Console.WriteLine("Copying: {0}", value);
				return;
			}

			if (IsCollision(key))
			{	System.Console.WriteLine("Collision: {0}", value);
				do
				{
					key = GetNewHashCode();
				} while (IsCollision(key));
			}

			if (!IsFirst)
			{
				key = 0;
				IsFirst = true;
			}
			carNumbers[key] = new HashItem(key, value);
			curSize++;
		}
		public bool Find(string value)
		{
			var key = GetHashCode(value);

			if (carNumbers[key].CarNumber == value)
			{
				return true;
			}

			foreach (var number in carNumbers)
			{
				if (number.CarNumber == value)	
				{
					return true;
				}
			}
			return false;
		}

		private int GetHashCode(string value)
		{
			int code = 0;
			for (int i = 0; i < value.Length; i++)
			{
				code += value[i];
			}
			return code % (carNumbers.Length);
		}
		private int GetNewHashCode()
		{
			return rnd.Next(0, carNumbers.Length);
		}
		private bool IsCollision(int key)
		{	
			foreach (var number in carNumbers)
			{
				if (number.Hash == key)	
				{
					return true;
				}
			}
			return false;
		}
		private bool IsCopy(int key, string value)
		{	
			foreach (var number in carNumbers)
			{
				if (number.CarNumber == value)	
				{
					return true;
				}
			}
			return false;
		}
		public void PrintAllHashTable()
		{
			for (int i = 0; i < carNumbers.Length; i++)
			{
				System.Console.WriteLine("Car number: {0}", carNumbers[i].CarNumber ?? "<None>");	
			}
		}
	}
}