/* You have been given a positive integer N. You need to find and print the
   Factorial of this number. The factorial of a positive integer N refers to the
   product of all number in the range from 1 to N.
*/
import java.util.*;
class Factorial {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int number, factorial = 1;
		number = sc.nextInt();
		// calculating factorial of the number
		for (int i = 1; i <= number; i++) {
			factorial *= i;
		}
		System.out.println(factorial);
	}
}
