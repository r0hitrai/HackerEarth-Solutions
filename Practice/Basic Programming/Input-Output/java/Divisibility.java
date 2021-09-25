/* You are provided an array A of size N that contains non-negative
   integers. Your task is to determine whether the number that is
   formed by selecting the last digit of all the N numbers is divisble
   by 10.
   Note: View the sample explanation section for more clarification.
*/
import java.util.*;
class Divisibility {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		int[] numbers = new int[size];
		// inserting input non-integers in numbers
		for (int i = 0; i < size; i++)
			numbers[i] = sc.nextInt();
		// checking if last digit is 0, which will be divisible by 10
		if (numbers[size - 1] % 10 == 0)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
