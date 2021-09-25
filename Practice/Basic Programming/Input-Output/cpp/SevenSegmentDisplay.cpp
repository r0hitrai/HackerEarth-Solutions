/* You all have seen a seven segment display.
   Alice got a number written in seven segment format where each
   segment was creatted used a matchstick.
   Example, if Alice gets a number 123 so basically Alice used 12
   matchsticks for this number.
   Alice is wondering what is the numerically largest value that
   she can generate by using at most the matchsticks that she
   currently posses. Help Alice out by telling her that number.
*/
#include<iostream>
using namespace std;
#define SIZE 100
int main() {
	int testCases, matchsticks, maxNumber, temp, totalMatchsticks, i, j;
	string number;
	cin >> testCases;
	/* running for each test case */
	for (i = 0; i < testCases; i++) {
		totalMatchsticks = 0;
		cin >> number;
		/* calculating matchsticks for each digit of the number */
		for (j = 0; j < number.size(); j++)  {
			temp = number[j] - '0';
			/* setting matchsticks for currenr digit */
			switch (temp) {
				case 0:
					matchsticks = 6;
					break;
				case 1:
					matchsticks = 2;
					break;
				case 2:
					matchsticks = 5;
					break;
				case 3:
					matchsticks = 5;
					break;
				case 4:
					matchsticks = 4;
					break;
				case 5:
					matchsticks = 5;
					break;
				case 6:
					matchsticks = 6;
					break;
				case 7:
					matchsticks = 3;
					break;
				case 8:
					matchsticks = 7;
					break;
				case 9:
					matchsticks = 6;
					break;
				default:
					cout << "Unknown\n";
					break;
			}
			totalMatchsticks += matchsticks;
		}
		/* if one stick left, then first digit will be 7 */
		if (totalMatchsticks % 2 == 1) {
			cout << "7";
			totalMatchsticks-=3;
		}
		/* calculating maximum digit number */
		for (int i = 0; i < totalMatchsticks; i+=2)
			cout << "1";
		cout << "\n";
	}
	return 0;
}
