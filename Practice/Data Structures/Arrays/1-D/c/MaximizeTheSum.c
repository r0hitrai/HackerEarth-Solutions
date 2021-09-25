/* You are given an array A of N integers. You want to choose some integers from 
   the array subject to the condition that the number of distinct integers chosen 
   should not exceed K. Your task is to maximize the sum of chosen numbers.
   You are given T test cases.
*/
#include<stdio.h>
// merge
void merge(long arr[], int left, int mid, int right) {
	// variables for loops
	int i, j, k;
	// size of leftArr
	int leftSize = mid - left + 1;
	// size of rightArr
	int rightSize = right - mid;
	// creating leftArr and rightArr
	long leftArr[leftSize], rightArr[rightSize];
	// copy items to leftArr
	for (i = 0; i < leftSize; i++)
		leftArr[i] = arr[left + i];
	// copy items to rightArr
	for (i = 0; i < rightSize; i++)
		rightArr[i] = arr[mid + 1 + i];
	// merging arrays
	i = 0; // index of leftArr
	j = 0; // index of rightArr
	k = left; // index of merged arr
	while (i < leftSize && j < rightSize) {
		if (leftArr[i] > rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	// copy remaining items from leftArr, if any
	while (i < leftSize) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	// copy remaining items from rightArr, if any
	while (j < rightSize) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}
// merge sort
void mergeSort(long num[], int start, int end) {
	// if array has atleast two elements
	if (start < end) {
		// mid element and avoiding overflow for large values
		int mid = start + (end - start) / 2;
		// sort first half
		mergeSort(num, start, mid);
		// sort second half
		mergeSort(num, mid + 1, end);
		// merge sorted subarrays
		merge(num, start, mid, end);
	}
}
// calculating maximum sum
long maxSum(long integers[], int size, int limit) {
	// loop variables
	int i, j;
	// maximum sum
	long sum = 0;
	// if size is less than limit
	if (size <= limit) {
		// then add all the integers
		for (i = 0; i < size; i++)
			// adding the positive integer in sum
			sum += integers[i];
	}
	// if not
	else {
		// index for storing sum of all occurance of each integers
		j = 0;
		// for all integers
		for (i = 1; i < size; i++) {
			// if integer is same
			if (integers[i] == integers[i - 1])
				// add 
				integers[j] += integers[i];
			// if not
			else
				// copy in the next position
				integers[++j] = integers[i];
		}
		// numbers of disticnt integers
		int sumsNo = j + 1;
		// sorting integers in descending order

		mergeSort(integers, 0, sumsNo - 1);
		// adding initial limit number of integers
		for (i = 0; i < limit; i++) {
			// if numbers of integers in integers are over
			if (i == sumsNo)
				// exit
				break;
			// add integer in sum
			sum += integers[i];
		}
	}
	// returning maximum sum
	return sum;
}
// main function
int main() {
	// number of test case
	int testCase;
	// scanning testCase
	scanf("%d", &testCase);
	// calculating for all testCase
	while (testCase--) {
		// length of array, maximum numbers of distinct integers, loop variables, counting current number of distinct integers
		int size, limit, i,	 j, count = 0;
		// scanning size and limit
		scanf("%d%d", &size, &limit);
		// array of integers, total sum
		long numbers[size], sum = 0;
		// number of positive integers
		int positiveNo = 0;
		// scanning all values of integers numbers and calculating positiveNo
		for (i = 0; i < size; i++) {
			// scanning integers
			scanf("%ld", &numbers[i]);
			// if positive integer
			if (numbers[i] > 0)
				// increment
				positiveNo++;
		}
		// sorting numbers in descending order
		mergeSort(numbers, 0, size - 1);
		// if all integers are positive
		if (positiveNo == size)
			// calculate sum using numbers
			sum = maxSum(numbers, size, limit);
		// if not
		else {
			// array of only positive integers
			long positiveNumbers[positiveNo];
			// positiveNumbers index
			j = 0;
			// copying all positive integers in positiveNumbers
			for (i = 0; i < size; i++) {
				// if integer is positive
				if(numbers[i] > 0) {
					// copy it in positiveNumbers
					positiveNumbers[j] = numbers[i];
					// increment positiveNumbers index
					j++;
				}
			}
			// calculate sum using positiveNumbers
			sum = maxSum(positiveNumbers, positiveNo, limit);
		}
		// printing required output
		printf("%ld\n", sum);
	}
	return 0;
}
