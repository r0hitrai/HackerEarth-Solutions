/* A natural number is a special if it consists of only digits 4 and 7. Find the 
   number of pairs of coprime special numbers (x,y) such that 1<=x<=y<=N.
*/
#include<stdio.h>
// calculating gcd of x and y
int gcd(int x, int y) {
	// if smaller number becomes 0
	if (x == 0)
		// return bigger number
		return y;
	// return gcd of bigger mod smaller, samller
	return gcd(y % x, x);
}
// main function
int main() {
	long number, digits = 0, count = 0;
	int size = 2, i = 0;
	scanf("%ld", &number);
	long temp = number;
	// calculating number of digits and size of arrya required
	while(temp != 0) {
		// removing last digit
		temp /= 10;
		// incrementing size by power of two
		size += size;
	}
	// array of numbers made up of 4 and 7
	long binary[size];
	// if number is more than 7, then only calculated required numebers made up of 4 and 7
	if (number >= 7) {
		// first number is 4
		binary[0] = 4;
		// second number is 7
		binary[1] = 7;
		// index of number to be calculated
		i = 2;
		// index of starting number to be appended
		int start = 0;
		// index of last number to be appended
		int end = 1;
		// using for looping to all numbers to be appended
		int j = start;
		// number of digits to be calculated
		long digitsNumber = 4;
		// multiplicatino factor to append digit in last
		long mul = 10;
		// is calculated number is greater or equal to input number
		int isMax = 0;
		// calculating required numbers made up of 4 and 7
		while (1) {
			// current number of digits for looping
			digits++;
			// for all number of digits to be calculated
			for (int k = 0; k < digitsNumber; k++) {
				// if index is at last number to be appended
				if (j > end)
					// reset
					j = start;
				// for first half numbers
				if (k < digitsNumber / 2)
					// appendding number
					binary[i] = binary[j] + (4 * mul);
				// for second half numbers
				else
					// appending number
					binary[i] = binary[j] + (7 * mul);
				// if maximum number reached, exit
				if (binary[i] > number) {
					isMax = 1;
					break;
				}
				i++;
				j++;
			}
			// if maximum number is reached, exit
			if (isMax)
				break;
			// start will be next to end
			start = end + 1;
			// end will be last index calculated
			end = i - 1;
			// j becomes start for loopiing in between
			j = start;
			// number of digits to be calculated increases by power of two
			digitsNumber += digitsNumber;
			// muiltiplication factor increases by 10
			mul *= 10;
		}
	}
	// for all items in binary array
	for (int j = 0; j < i; j++) {
		// with all next items in binary array
		for (int k = j + 1; k < i; k++) {
			// if gcd of them is 1
			if (gcd(binary[j], binary[k]) == 1) {
				// increment count by 1
				count++;
			}
		}
	}
	// printing final result
	printf("%ld\n", count);
	return 0;
}
