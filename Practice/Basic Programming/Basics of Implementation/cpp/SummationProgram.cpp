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
#include<iostream>
#include<fstream>
using namespace std;
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
	ifstream fin("input.txt");
	int testCase;
	fin >> testCase;
	while (testCase--) {
		long long int number;
		fin >> number;
		long long int result = solve(number);
		cout << result << endl;
	}
	return 0;
}
