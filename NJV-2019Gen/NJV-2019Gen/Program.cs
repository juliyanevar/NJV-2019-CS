using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using lib;
 
namespace CS
{
	class Program
	{

		public static byte func()		{
			Lib lib = new Lib();
			byte funcs = (byte)(lib.sqrt(9));
			return funcs;
			}
		static void Main(string[] args)
		{
			Lib lib = new Lib();
			byte qs;
			byte x = (byte)((int)func());
			byte y;
			byte z;
			byte d;
			string sa;
			string sb;
			string sc;
			bool f;
			bool q;
			x = (byte)((int)x >> 1);
			f = true;
			qs = (byte)(lib.sqrt(8));
			y = (byte)(lib.pow(x, 5));
			z = (byte)((int)x + 0xfe);
			if(x > 5) {
			x = (byte)(3);
			}
			else {
			x = (byte)(5);
			}
			sa = "1234567890";
			sb = "123456789";
			Console.WriteLine(z);
			Console.WriteLine(qs);
			Console.WriteLine(y);
			Console.WriteLine("primer");
			Console.WriteLine(x);
			}
	}
}