/* You are given a binary array A of N elements. The array consists of 0's
   and 1's. You can perform the following operations as many times as
   possible:
   - Select a subarray starting from the first index that is inversion-free
   and delete it.
   Determine the minimum number of operations to delete the entire
   array.
*/
#include<iostream>
using namespace std;
int main() {
	int testCase, size, inversion, operation;
	cin >> testCase;
	// calculating for every test case
	for (int i = 0; i < testCase; i++) {
		operation = inversion = 0;
		cin >> size;
		int numbers[size];
		// setting values in numbers
		for (int j = 0; j < size; j++)
			cin >> numbers[j];
		for (int j = 0; j < size - 1; j++) {
			if (numbers[j] > numbers[j + 1])
				inversion++;
		}
		operation = inversion + 1;
		cout << operation << endl;
	}
	return 0;
}
