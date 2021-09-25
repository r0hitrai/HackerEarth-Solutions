/* You have been given an array A of size N consisting of positive
   integers. You need to find and print the product of all the number in
   this array Modulo 1000000000 + 7.
*/
import java.util.*;
class FindProduct {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		long product = 1;
		int[] numbers = new int[size];
		// putting input in numbers
		for (int i = 0; i < size; i++)
			numbers[i] = sc.nextInt();
		// calculating of product of all numbers
		for (int i = 0; i < size; i++)
			product = (product * numbers[i]) % (1000000000 + 7);
		System.out.println(product);
	}
}
