/* You are given an integer array A. Your task is to calculate the sum
   of absolute difference of indices of first and last occurrence for
   every integer that is present in array A.
   Formally, if element x occurs m times in the array at indices B1, B2,
   B3,...,Bm, then the answer for x will be Bm-B1 if array B is stored.
   You are required to calculate the sum of the answer for every such x
   that occurs in the array.
*/
#include<stdio.h>
/* Merges two subarrays of arr[]
   First subarray is arr[left...mid]
   Second subarray is arr[mid+1...right]
*/
void merge(long loc[], long arr[], int left, int mid, int right) {
	int i, j, k;
	int leftSize = mid - left + 1;
	int rightSize = right - mid;
	// create temp arrays
	long leftArr[leftSize], rightArr[rightSize], leftLoc[leftSize], rightLoc[rightSize];
	// copy data to temp arrays
	for (i = 0; i < leftSize; i++) {
		leftArr[i] = arr[left + i];
		leftLoc[i] = loc[left + i];
	}
	for (i = 0; i < rightSize; i++) {
		rightArr[i] = arr[mid + 1 + i];
		rightLoc[i] = loc[mid + 1 + i];
	}
	// Merge the temp arrays back into arr[left...right]
	i = 0; // initial index of first subarray
	j = 0; // initial index of second subarray
	k = left; // initial index of merged subarray
	while (i < leftSize && j < rightSize) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			loc[k] = leftLoc[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			loc[k] = rightLoc[j];
			j++;
		}
		k++;
	}
	// copy the remaining values of leftArr[]
	while (i < leftSize) {
		arr[k] = leftArr[i];
		loc[k] = leftLoc[i];
		i++;
		k++;
	}
	// copy the remaining values of rightArr[]
	while (j < rightSize) {
		arr[k] = rightArr[j];
		loc[k] = rightLoc[j];
		j++;
		k++;
	}
}
/* left is left index and right is right index of the sub-array
   of arr to be sorted
*/
void mergeSort(long loc[], long arr[], int left, int right) {
	if (left < right) {
		// to avoid overflow for large l and h
		int mid = left + (right - left) / 2;
		//sort first and second halves
		mergeSort(loc, arr, left, mid);
		mergeSort(loc, arr, mid + 1, right);
		// merger both subarrays
		merge(loc, arr, left, mid, right);
	}
}
//main function
int main() {
	long testCase, size, sum;
	scanf("%ld", &testCase); // setting number of test cases
	// calculating for every test case
	while (testCase--) {
		sum = 0;
		scanf("%ld", &size); // setting size of array
		long numbers[size], locations[size]; // array containing all numbers and their locations
		// setting values in numbers and their locations arrays
		for (int i = 0; i < size; i++) {
			scanf("%ld", &numbers[i]);
			locations[i] = i;
		}
		mergeSort(locations, numbers, 0, size - 1); // sorting numbers array while maintaining their correct locations
		int i = 0;
		// calculating total sum of every number's first and last occurence
		while (i < size) {
			// finding last occurence of current number
			for (int j = i; j < size; j++) {
				// if current number is equal to next nubmer, then next iteration of loop
				if (numbers[i] == numbers[j + 1])
					continue;
				sum += (locations[j] - locations[i]); // adding difference of last and first occurence of current number in sum
				i = j + 1; // setting current number to first occurence of next different number
				break;
			}
		}
		printf("%ld\n", sum); /* printing final result */
	}
	return 0;
}
