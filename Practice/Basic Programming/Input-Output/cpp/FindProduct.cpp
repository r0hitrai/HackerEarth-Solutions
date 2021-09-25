/* You have been given an array A of size N consisting of positive
   integers. You need to find and print the product of all the number in
   this array Modulo 1000000000 + 7.
*/
#include<iostream>
using namespace std;
int main() {
	int size;
	long product = 1;
	cin >> size;
	int numbers[size];
	// putting input in numbers
	for (int i = 0; i < size; i++)
		cin >> numbers[i];
	// calculating of product of all numbers
	for (int i = 0; i < size; i++)
		product = (product * numbers[i]) % (1000000000 + 7);
	cout << product << "\n";
	return 0;
}
