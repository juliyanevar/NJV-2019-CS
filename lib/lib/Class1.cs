using System;

namespace lib
{
    public class Lib
    {
        public static byte pow(byte n, byte m)
        {
            double d = Math.Pow(n, m);
            return Convert.ToByte(d);
        }


        public static byte sqrt(byte n)
        {
            double d = Math.Sqrt(Convert.ToDouble(n));
            return Convert.ToByte(d);
        }
    }
}
