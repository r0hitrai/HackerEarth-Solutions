/* You are given an array of numbers. Ai which contains positive as well as
   negative numbers. The cost of the array can be defined as C(X).
   C(x)=|A1+T1|+|A2+T2|+...+|An+Tn|, where T is
   the transfer array which contains N zeros initially.
   You need to minimize this cost. You can transfer value from one array
   element to another if and only if the distance between them is at most K.
   Also, transfer value can't be transferred further.
*/
#include<iostream>
using namespace std;
int main() {
	long sum1 = 0, counter = 0, m, size, k, cost = 0;
	cin >> size >> k;
	m = k;
	long numbers[size];
	// setting input values in numbers
	for (int i = 0; i < size; i++) {
		cin >> numbers[i];
	}
	// for each value in numbers
	for (int i = 0; i < size; i++) {
		// if positive value, then increment counter and add value to sum
		if (numbers[i] >= 0) {
			counter++;
			sum1 += numbers[i];
			m = k;
		}
		// if negative value, then
		else {
			// if it is first value in numbers, then print sum of all numbers
			if (counter == 0) {
				// calculating final cost */
				for (int i = 0; i < size; i++) {
					// if number is negative, then subtract
					if (numbers[i] < 0)
						cost -= numbers[i];
					// if number is positive, then add
					else
						cost += numbers[i];
				}
				cout << cost << "\n";
				return 0;
			}
			// if it is not the first value, then
			else {
				m -= 1;
				if (m < 0) {
					sum1 -= numbers[i];
				}
				else {
					sum1 += numbers[i];
				}
			}
		}
	}
	// if number is negative, then subtract
	if (sum1 < 0)
		sum1 = 0 - sum1;
	cout << sum1 << "\n";
    return 0;
}
