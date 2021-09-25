/* You have been given a positive integer N. You need to find and print the
   Factorial of this number. The factorial of a positive integer N refers to the
   product of all number in the range from 1 to N.
*/
#include<iostream>
using namespace std;
int main() {
	int number, factorial = 1;
	cin >> number;
	// calculating factorial of the number
	for (int i = 1; i <= number; i++) {
		factorial *= i;
	}
	cout << factorial;
	return 0;
}
