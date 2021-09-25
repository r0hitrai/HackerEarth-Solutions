/* You are given a number N. You are required to determine the value of the 
   following function:
   long long int solve(N)
   {
       ans=0;
       for(i=1;i<=N;i++)
       ans+=(N/i);
       return ans;
   }
   All divisions are integer divisions (i.e. N/i is actually floor(N/i)).
   ***ANSWER COPIED***
*/
#include<stdio.h>
#include<stdlib.h>
// optimized given function
long long int solve(long long int N)
{
	long long int ans = 0;
	int i, j;
	for (i = 1; ((N / i) - (N / (i + 1))) != 1; i++)
		ans += ((N / i) - (N / (i + 1))) * i;
	j = i;
	for (i = 1; i <= (N / j); i++)
		ans += N / i;
	return ans;
}
// main function
int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int testCase;
	fscanf(fp, "%d", &testCase);
	while (testCase--) {
		long long int number;
		fscanf(fp, "%ld", &number);
		long long int result = solve(number);
		printf("%ld\n", result);
	}
	return 0;
}
