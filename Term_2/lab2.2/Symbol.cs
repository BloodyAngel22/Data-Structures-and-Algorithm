using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace lab2._2
{
	public class Symbol
	{
		public char Letter { get; set; }
		public int Counter { get; set; }
		public Symbol(char letter, int counter)
		{
			Letter = letter;
			Counter = counter;	
		}
	}
}