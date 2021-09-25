/* You are required to enter a word that consists of x and y that
   denote the number of Zs and Os respectively. The input word is
   considered similor to word zoo if 2 * x = y.
   Determine if the entered word is similar to word zoo.
   For example, words such as zzoooo and zzzoooooo are similar
   to word zoo but not the words such as zzooo and zzzooooo.
*/
#include<iostream>
using namespace std;
#define SIZE 20
int main() {
	int i, noOfZ = 0, noOfO = 0;
	char word[SIZE];
	// inserting default values in word
	for (i = 0; i < SIZE; i++)
		word[i] = 'x';
	// inserting input string in word
	for (i = 0; i < SIZE; i++)
		cin >> word[i];
	i = 0;
	// counting no of Zs
	while (word[i] == 'z') {
		noOfZ++;
		i++;
	}
	// counting no of Os
	while (word[i] == 'o') {
		noOfO++;
		i++;
	}
	// checking if no of Os are twice of that of Zs
	if (noOfO == 2 * noOfZ)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
