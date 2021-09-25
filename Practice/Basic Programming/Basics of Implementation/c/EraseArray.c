/* You are given a binary array A of N elements. The array consists of 0's
   and 1's. You can perform the following operations as many times as
   possible:
   - Select a subarray starting from the first index that is inversion-free
   and delete it.
   Determine the minimum number of operations to delete the entire
   array.
*/
#include<stdio.h>
int main() {
	int testCase, size, inversion, operation;
	scanf("%d", &testCase);
	/* calculating for every test case */
	for (int i = 0; i < testCase; i++) {
		operation = inversion = 0;
		scanf("%d", &size);
		int numbers[size];
		/* setting values in numbers */
		for (int j = 0; j < size; j++)
			scanf("%d", &numbers[j]);
		for (int j = 0; j < size - 1; j++) {
			if (numbers[j] > numbers[j + 1])
				inversion++;
		}
		operation = inversion + 1;
		printf("%d\n", operation);
	}
	return 0;
}
