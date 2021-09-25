/* Arpasland has surrounded by attackers. A truck enters the city. The driver
   claims the load is food and medicine from Iranians. Ali is one of the
   soldiers in Arpasland. He doubts about the truck, maybe it's from the
   siege. He knows that a tag is valid if the sum of every two consecutive
   digits of it is even and its letter is not a vowel. Determine if the tag of the
   truck is valid or not.
   We consider the letters "A", "E", "I", "O", "U", "Y" to be vowels for this
   problem.
*/
#include<iostream>
using namespace std;
#define SIZE 9
#define VOWELS 6
int main() {
	char tag[SIZE];
	char VOWEL[VOWELS] = {'A', 'E', 'I', 'O', 'U', 'Y'};
	cin >> tag;
	// checking each character for validity
	for (int i = 0; i < SIZE - 1; i++) {
		// ignoring some places
		if (i == 1 || i == 5 || i == 6)
			continue;
		// chaecking if the letter is not a vowel
		if (i == 2) {
			// checking with every vowel
			for (int j = 0; j < VOWELS; j++) {
				// if vowel then invalid
				if(tag[i] == VOWEL[j]) {
					cout << "invalid\n";
					return 0;
				}
			}
		}
		// checking if every two consequetive digits sum is not even
		else if (((tag[i] - '0') + (tag[i + 1] - '0')) % 2 != 0) {
			cout << "invalid\n";
			return 0;
		}
	}
	cout << "valid\n";
	return 0;
}
