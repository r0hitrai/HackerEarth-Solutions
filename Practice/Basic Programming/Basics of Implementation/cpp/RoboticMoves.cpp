/* A robot's initial position is (0,0) and it can only move along X-
   axis. It has N moves to make and in each move, it will select one of
   the following options:
   1. Go to (X-1,0) from (X,0)
   2. Go to (X+1,0) from (X,0)
   3. Remain at its current position
   Your task is to calculate sum of all(abs(X)+abs(Y)) for all 
   reachable (X,Y).
   Note: Here, abs denotes the absolute value.
*/
#include<iostream>
using namespace std;
int main() {
	int testCase;
	long move, sum;
	cin >> testCase; // setting number os test cases
	// for every test case
	while (testCase--) {
		cin >> move; // setting number of moves
		sum = (move * ( move + 1 )) / 2; // calculating total sum of absolute value of all forward moves
		sum = move * ( move + 1 ); // calculating total sum of absolute value of each move
		cout << sum << endl; // printing final result
	}
	return 0;
}
