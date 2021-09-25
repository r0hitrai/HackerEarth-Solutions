/* You have been given a String S consisting of uppercase and lowercase
   English alphabets. You need to change the case of each alphabet in this
   String. That is, all the uppercase letters should be converted to lowercase
   and all the lowercase letters should be converted to uppercase. You need to
   then print the resultant String to output.
*/
#include<iostream>
using namespace std;
#define SIZE 100
int main() {
	char string[SIZE];
	cin >> string;
	int i = 0;
	// for every character in string
	while (string[i] != '\0') {
		// if it is UPPERCASE, convert it to LOWERCASE
		if (string[i] > 64 && string[i] < 97)
			string[i] += 32;
		// if it is LOWERCASE, convert it to UPPERCASE
		else
			string[i] -= 32;
		i++;
	}
	cout << string << "\n";
	return 0;
}
