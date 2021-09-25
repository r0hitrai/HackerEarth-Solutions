/* You all have seen a seven segment display.
   Alice got a number written in seven segment format where each
   segment was creatted used a matchstick.
   Example, if Alice gets a number 123 so basically Alice used 12
   matchsticks for this number.
   Alice is wondering what is the numerically largest value that
   she can generate by using at most the matchsticks that she
   currently posses. Help Alice out by telling her that number.
*/
#include<stdio.h>
#define SIZE 100
int main() {
	int testCases, matchsticks, maxNumber, temp, totalMatchsticks, i, j;
	char c;
	scanf("%d", &testCases);
	char number[testCases][SIZE];
	/* setting default value in numbers array */
	for (i = 0; i < testCases; i++) {
		for(j = 0; j < SIZE; j++)
			number[i][j] = 'a';
	}
	/* running for each test case */
	for (i = 0; i < testCases; i++) {
		/* setting default value in numbers array */
		for (int l = 0; l < testCases; l++) {
			for(int m = 0; m < SIZE; m++)
				number[l][m] = 'a';
		}
		totalMatchsticks = 0;
		j = 0;
		scanf("%s", &number[i][0]);
		/* calculating matchsticks for each digit of the number */
		while ((number[i][j] != '\0') && (number[i][j] != 'a')) {
			temp = number[i][j] - '0';
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
					printf("Unknown\n");
					break;
			}
			totalMatchsticks += matchsticks;
			j++;
		}
		/* if one stick left, then first digit will be 7 */
		if (totalMatchsticks % 2 == 1) {
			printf("7");
			totalMatchsticks-=3;
		}
		/* calculating maximum digit number */
		for (int i = 0; i < totalMatchsticks; i+=2)
			printf("1");
		printf("\n");
		
	}
	return 0;
}
