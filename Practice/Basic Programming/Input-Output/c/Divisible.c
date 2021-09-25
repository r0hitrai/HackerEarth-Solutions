/* You are given an array A of size N that contains integers. Here, N
   is an even number. You are required to perform the following
   operations:
   1. Divide the array of numbers in two equal halves
      Note: Here, two equal parts of a test case are created by
      dividing the array into two equal parts.
   2. Take the first digit of the numbers that are available in the
      first half of the array (first 50% of the test case)
   3. Take the last digit of the numbers that are available in the
      second half of the array (second 50% of the code test case)
   4. Generate a number by using the digits that have been
      selected in the above steps.
   Your task is to determine whether the newly-generated number is
   divisible by 11.
*/
#include<stdio.h>
int main() {
	int size, mid, number = 0, oddSum = 0, evenSum = 0;
	scanf("%d", &size);
	int numbers[size];
	/* inserting input numbers */
	for (int i = 0; i < size; i++)
		scanf("%d", &numbers[i]);
	int digits[size];
	mid = size / 2;
	/* getting first digit of first half of numbers */
	for (int i = 0; i < mid; i++) {
		while (numbers[i] > 9)
			numbers[i] /= 10;
		digits[i] = numbers[i];
	}
	/* getting last digit of second half of numbers */
	for (int i = mid; i < size; i++)
		digits[i] = numbers[i] % 10;
	/* sum of odd place digits */
	for (int i = 0; i < size; i += 2)
		oddSum += digits[i];
	/* sum of even place digits */
	for (int i = 1; i < size; i += 2)
		evenSum += digits[i];
	/* checking if number is divisible by 11 */
	if (((oddSum - evenSum) == 0) || ((oddSum - evenSum) % 11 == 0))
		printf("OUI\n");
	else
		printf("NON\n");
	return 0;
}
