import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class qwer {

	public static void main(String[] args) {
		System.out.println(args[0]);
//		String order = "test.java";
		
		Runtime rt = Runtime.getRuntime();
		
		try {
			rt.exec("javac " + args[0]);
//			BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));
//			String line = null;
			
			System.out.println("javac");
			
			StringTokenizer tokens = new StringTokenizer(args[0]);
			String name = tokens.nextToken(".");
			
			Thread.sleep(3000);
			
			rt.exec("java " + name);
			
			System.out.println(name);
		} catch(Exception e) {
			System.out.println("Error : " + e);
		}
	}

}
