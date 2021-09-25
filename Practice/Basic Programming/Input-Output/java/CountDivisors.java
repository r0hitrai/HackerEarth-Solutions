/* You have been given 3 integers - l, r and k. Find how many numbers
   between l anr r (both includive) are divisible by K. You do not need to print
   these numbers, you can just have to find their count.
*/
import java.util.*;
class CountDivisors {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int start, end, divisor, dividendNo = 0;
		start = sc.nextInt();
		end = sc.nextInt();
		divisor = sc.nextInt();
		// checking for every number between start and end inclusovely
		for (int i = start; i <= end; i++) {
			// counting divisible numbers
			if (i % divisor == 0)
				dividendNo++;
		}
		System.out.println(dividendNo);
	}
}
