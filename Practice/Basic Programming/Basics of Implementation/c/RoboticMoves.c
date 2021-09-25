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
#include<stdio.h>
int main() {
	int testCase;
	long move, sum;
	scanf("%d", &testCase); /* setting number os test cases */
	/* for every test case */
	while (testCase--) {
		scanf("%ld", &move); /* setting number of moves */
		sum = (move * ( move + 1 )) / 2; /* calculating total sum of absolute value of all forward moves */
		sum = move * ( move + 1 ); /* calculating total sum of absolute value of each move */
		printf("%ld\n", sum); /* printing final result */
	}
	return 0;
}
