using lab2._1;

HashTable btable = new (10);
List<string> carNumbers = new ()
{
	"Б469АБ", 
	"В928ВЕ", 
	"О127НО", 
	"П262MB", 
	"А123ОА", 
	"Б476ЛЛ", 
	// "П122MB", 
	// "А123АО", 
	// "Ш188ПО", 
	// "П137АО", 
	// "П137АО", 
};
foreach (var number in carNumbers)
{
	btable.Add(number);
}
System.Console.WriteLine();
btable.PrintAllHashTable();

System.Console.WriteLine();
System.Console.WriteLine("Search");
System.Console.WriteLine(btable.Find("П262MB"));
System.Console.WriteLine(btable.Find("О127НО"));
System.Console.WriteLine(btable.Find("Ш188ПО"));