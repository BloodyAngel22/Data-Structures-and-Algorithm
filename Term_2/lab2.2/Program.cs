using System.Security.Cryptography;
using System.Text;
using lab2._2;

string source = "Hello world!";

HashTable table = new(source);
table.Print();
table.Find('l');