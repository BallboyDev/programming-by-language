using System;

namespace Test{
	class Program{
		public static int st=0, ba=0;
		public static void Main(string[] args){
			
			
			Random r = new Random();
			int[] arr = new int[3];
			arr[0] = r.Next(9);
			arr[1] = r.Next(9);
			arr[2] = r.Next(9);
			
			while(true){
				//Console.WriteLine("{0}, {1}, {2}", a, b, c);
				if(arr[0] == arr[1]) arr[1] = r.Next(9);
				if(arr[0] == arr[2] || arr[1] == arr[2]) arr[2] = r.Next(9);
				if(arr[0] != arr[1] && arr[1] != arr[2] && arr[0] != arr[2]) break;
			}
			
			Console.WriteLine("{0}, {1}, {2}", arr[0], arr[1], arr[2]);
			
			String s = Console.ReadLine();
			int x = int.Parse(s.Substring(0, 1));
			int y = int.Parse(s.Substring(1, 1));
			int z = int.Parse(s.Substring(2, 1));
			
			Console.WriteLine("{0}, {1}, {2}", x, y, z);
			
			int x_pos, y_pos, z_pos;
			
			x_pos = Array.IndexOf(arr, x);
			judge(x_pos, 0);
			y_pos = Array.IndexOf(arr, y);
			judge(y_pos, 1);
			z_pos = Array.IndexOf(arr, z);
			judge(z_pos, 2);
			Console.Write("st = {0}, ba = {1}", st, ba);
		}
		
		public static int judge(int pos, int jud){
			if(pos >= 0 && jud == pos){
				st++;
				return 1;
			}
			else if(pos >= 0 && jud != pos){
				ba++;
				return 2;
			}
			else
				return 3;
		}
	}
}
