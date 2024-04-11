using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace lab2._1
{
	public struct HashItem
	{
		public HashItem(int hash, string value)
		{
			Hash = hash;
			CarNumber = value;
		}
		public int? Hash { get; set; }
		public string? CarNumber { get; set; }
	}
}