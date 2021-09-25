/* You have been given a String S. You need to find and print whether this
   string is a palindrome or not. If yes, print "YES", else print
   "NO".
*/
#include<iostream>
using namespace std;
#define SIZE 100
int main() {
	char string[SIZE], front, back, mid;
	cin >> string;
	int length = 0;
	// calculating length of string
	while (string[length] != '\0') 
		length++;
	mid = length / 2;
	front = 0;
	back = length - 1;
	// checking for palindrome
	while (front < back) {
		// if alphabet id not same, then not a palindrome
		if (string[front] != string[back]) {
			cout << "NO\n";
			return 0;
		}
		front++;
		back--;
	}
	cout << "YES\n";
	return 0;
}
