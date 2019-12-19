using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace CS
{
	class Program
	{

		static void Main(string[] args)
		{
			byte qs;
			byte x = 2;
			byte y;
			byte z;
			string sa;
			string sb;
			string sc;
			bool f;
			f = false;
			qs = Lib.sqrt(4);
			y = Lib.pow(2, 5);
			z = (x + 3) / y;
			if(x > 5) {
			x = 3;
			}
			else {
			x = 5;
			}
			sa = "1234567890";
			sb = "123456789";
			Console.WriteLine("primer");
			Console.WriteLine(x);
			return 0;
			}
	}
}