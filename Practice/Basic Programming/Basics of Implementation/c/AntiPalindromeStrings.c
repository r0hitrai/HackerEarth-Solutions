/* You are given a string S containig only lowercase aphabets. You can
   swap two adjacent characters any number of times (including 0).
   A string is called anti-palindrome if it is not a palindrome. If it
   is possible to make a string anti-palindrome, then find the
   lexicographically smallest anti-palindrome. Otherwise, print -1.
*/
#include<stdio.h>
#define SIZE 200000
// merging subarrays in sorted order
void merge(char arr[], int left, int mid, int right) {
	int i, j, k;
	// size of left subarray
	int leftSize = mid - left + 1;
	// size of right subarray
	int rightSize = right - mid;
	// creating temporary subarrays
	char leftArr[leftSize], rightArr[rightSize];
	// copying left subarray
	for (i = 0; i < leftSize; i++)
		leftArr[i] = arr[left + i];
	// copying right subarray
	for (i = 0; i < rightSize; i++)
		rightArr[i] = arr[mid + 1 + i];
	i = 0; //initial index of left subarray
	j = 0; //initial index of right subarray
	k = left;
	// merging subarrays in sorted array
	while (i < leftSize && j < rightSize) {
		// putting smaller value from left subarray to array
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		}
		// putting smaller value from right subarray to array
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	// copying remaining elements from left subarray in array
	while (i < leftSize) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	// copying remaining elements from right subarray in array
	while (j < rightSize) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}
// merge sort
void mergeSort(char arr[], int left, int right) {
	if (left < right) {
		// to avoid overflow for larger left and right
		int mid = left + (right - left) / 2;
		// sort first subarray
		mergeSort(arr, left, mid);
		// sort second subarray
		mergeSort(arr, mid + 1, right);
		// merge first and second subarray
		merge(arr, left, mid, right);
	}
}
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		char string[SIZE];
		scanf("%s", string);
		int length = 0;
		while (string[length] != '\0')
			length++;
		int i = 0;
		int j = length - 1;
		int isPalindrome = 1;
		while (i < j) {
			if (string[i] != string[j]) {
				isPalindrome = 0;
				break;
			}
			i++;
			j--;
		}
		if (isPalindrome)
			printf("-1\n");
		else {
			mergeSort(string, 0, length - 1);
			printf("%s\n", string);
		}
	}
	return 0;
}
