/* You are given an array A of N elements. Now you need to choose the
   best index of this array A. An index of the array is called best if the
   special sum of this index is maximum across the special sum of the
   other indices.
   To calculate the special sum for any index i, you pick the first element
   that is A[i] and add it to your sum. Now you pick next two elements i.e.
   A[i+1] and A[i+2] and add both of them to your sum. Now you
   will pick the next 3 elements and this continues till the index for which
   it is possible to pick the elements.
   Find the best index and in the output print its corresponding special
   sum. Note that there may be more than one best indices but you need
   to only print the maximum special sum.
*/
#include<stdio.h>
int main() {
	int size, start, end, seq = 2, totalSum = 0, k = 0;
	long sum, maxSum = -1000000000;
	scanf("%d", &size);
	int numbers[size];
	long sums[size + 1];
	sums[0] = 0;
	/* putting values in numbers and their cumulative sum in sums */
	for (int i = 0; i < size; i++) {
		scanf("%d", &numbers[i]);
		sums[i + 1] = sums[i] + numbers[i];
	}
	/* calculating maximum special sum among all numbers */
	for (int i = size - 1; i >= 0; i--) {
		sum = sums[size] - sums[i];
		start = size - k;
		/* subtracting last pair of numbers which are not matching the sequence */
		for (int j = start; j < size; j++) {
			sum -= numbers[j];
		}
		/* setting maximum special sum */
		if (sum > maxSum)
			maxSum = sum;
		k++;
		/* restting last pair sequence value */
		if (k == seq) {
			k = 0;
			seq++;
		}
	}
	printf("%ld\n", maxSum);
	return 0;
}
