using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.Text;

namespace lab2._2
{
	public class HashTable
	{
		private Symbol[] table;
		public HashTable(string source)
		{
			table = new Symbol[Int16.MaxValue];
			Hash(source);
		}
		private void Hash(string source)
		{
			for (int i = 0; i < source.Length; i++)
			{
				var hash = (Int16)Math.Abs(source[i].GetHashCode());
				if (table[hash] == null)
				{
					table[hash] = new Symbol(source[i], 1);
				}
				else
				{
					table[hash].Counter++;
				}
			}
		}
		public void Print()
		{
			foreach (var item in table)
			{
				if (item != null)	
				{
					System.Console.Write(item.Letter + " " + item.Counter + ", ");
				}
			}
			System.Console.WriteLine();
		}
		public void Find(char letter)
		{
			var hash = (Int16)Math.Abs(letter.GetHashCode());
			if (table[hash] == null)
			{
				return;
			}

			System.Console.WriteLine(table[hash].Letter + " " + table[hash].Counter + " " + hash);
		}
	}
}