/* Your program is to use the brute-force approach in order to find the
   Answer to life, the Universe, and Everything. More precisely... rewrite small
   numbers from input to output. Stop processing input after reading in the
   number 42. All numbers at input are integers of one or two digits.
*/
#include<stdio.h>
int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int number;
	scanf("%d", &number);
	/* print number while we don't get 42 */
	while (number != 42) {
		printf("%d\n", number);
		scanf("%d", &number);
	}
	return 0;
}
