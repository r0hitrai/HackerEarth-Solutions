/* You are given a number N. You are required to determine the value of the 
   following function:
   long long int solve(N)
   {
       ans=0;
       for(i=1;i<=N;i++)
       ans+=(N/i);
       return ans;
   }
   All divisions are integer divisions (i.e. N/i is actually floor(N/i)).
   ***ANSWER COPIED***
*/
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
class SummationProgram {
	// optimized given function
	static long solve(long N)
	{
		long ans = 0;
		int i, j;
		for (i = 1; ((N / i) - (N / (i + 1))) != 1; i++)
			ans += ((N / i) - (N / (i + 1))) * i;
		j = i;
		for (i = 1; i <= (N / j); i++)
			ans += N / i;
		return ans;
	}
	// main function
	public static void main(String args[]) {
		try {
			File fin = new File("input.txt");
			Scanner sc = new Scanner(fin);
			int testCase;
			testCase = sc.nextInt();
			for (int i = 0; i < testCase; i++) {
				long number;
				number = sc.nextLong();
				long result = solve(number);
				System.out.println(result);
			}
		}
		catch (FileNotFoundException e) {
			System.out.println(e);
		}
	}
}
