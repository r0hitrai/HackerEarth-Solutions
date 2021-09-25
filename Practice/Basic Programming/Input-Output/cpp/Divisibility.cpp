/* You are provided an array A of size N that contains non-negative
   integers. Your task is to determine whether the number that is
   formed by selecting the last digit of all the N numbers is divisble
   by 10.
   Note: View the sample explanation section for more clarification.
*/
#include<iostream>
using namespace std;
int main() {
	int size;
	cin >> size;
	int numbers[size];
	// inserting input non-integers in numbers
	for (int i = 0; i < size; i++)
		cin >> numbers[i];
	// checking if last digit is 0, which will be divisible by 10
	if (numbers[size - 1] % 10 == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
