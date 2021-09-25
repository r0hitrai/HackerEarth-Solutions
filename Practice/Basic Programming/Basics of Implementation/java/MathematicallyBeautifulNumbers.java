/* While playing a mental math game, you realize that the number k is
   mathematically beautiful.
   You then realize that the number x can be mathematically beautiful if
   it is represented as a sum of a sequence where each element is a
   power of k and all the numbers in the sequence are different.
   Your task is to determine whether the number is mathematically
   beautiful.
*/
import java.util.Scanner;
class MathematicallyBeautifulNumbers {
	// calculatiing neatest sum to number
	static long nearestSum(long number, long value, long power) {
		long sum = 0; // nearest sum
		// if value power is more than number, then don't go further
		if (power > number) {
			return 0;
		}
		// if value power is less than or equal to number, then go to next power
		else {
			sum = nearestSum(number, value, power * value); // calling itself with next power
		}
		// if next sum becomes more than number, then return sum without adding
		if ((sum + power) > number)
			return sum;
		// if next sum becomes less than or equal to number, then return next sum
		else
			return sum += power;
	}
	// main function
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long testCase, number, value, result;
		testCase = sc.nextLong(); // setting number of test cases
		// for every test case
		for (int i = 0; i < testCase; i++) {
			number = sc.nextLong();
			value = sc.nextLong(); // setting x and k
			result = nearestSum(number, value, value); // calling nearestSum()
			// if nearest sum is equal to or 1 less than number, then print YES
			if ((result == number) || (++result == number))
				System.out.println("YES");
			// if nearest sum id not equal to nor 1 less than number, then print NO
			else
				System.out.println("NO");
		}
	}	
}
