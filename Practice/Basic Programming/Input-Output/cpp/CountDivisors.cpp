/* You have been given 3 integers - l, r and k. Find how many numbers
   between l anr r (both includive) are divisible by K. You do not need to print
   these numbers, you can just have to find their count.
*/
#include<iostream>
using namespace std;
int main() {
	int start, end, divisor, dividendNo = 0;
	cin >> start >> end >> divisor;
	// checking for every number between start and end inclusovely
	for (int i = start; i <= end; i++) {
		// counting divisible numbers
		if (i % divisor == 0)
			dividendNo++;
	}
	cout << dividendNo;
	return 0;
}
