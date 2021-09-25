/* You are provided an array A of size N that contains non-negative
   integers. Your task is to determine whether the number that is
   formed by selecting the last digit of all the N numbers is divisble
   by 10.
   Note: View the sample explanation section for more clarification.
*/
#include<stdio.h>
int main() {
	int size;
	scanf("%d", &size);
	int numbers[size];
	/* inserting input non-integers in numbers */
	for (int i = 0; i < size; i++)
		scanf("%d", &numbers[i]);
	/* checking if last digit is 0, which will be divisible by 10 */
	if (numbers[size - 1] % 10 == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
