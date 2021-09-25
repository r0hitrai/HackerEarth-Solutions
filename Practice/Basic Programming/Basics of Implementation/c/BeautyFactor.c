/* You are given a positive integer n. The beauty factor of a number is
   the sum of digits obtained till the obtained sum is a single digit.
   Example
   - Beauty factor of 1987 = 1+9+8+7 = 25 = 2+5 = 7
   - Beauty factor of 10 = 1+0 = 1
   You are given a beauty factor, b. Your task is to find a minimum
   number (n) of length k whose beauty factor is b.
   Here, the length of a number is defined as the number of digits a
   number has.
   Note: The digits of the number in the output must be distinct and 
   must be a positive integer.
*/
#include<stdio.h>
// calculate sum of all digits in the number
int digitsSum(int num) {
	int sum = 0;
	// taking last digint and adding in to the sum and removing it from number
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main() {
	int beauty, length;
	scanf("%d%d", &beauty, &length);
	int digits[length]; // array of digits if k length
	// setting inital digits which are not 0 and not repeated
	for (int i = 0; i < length; i++)
		digits[i] = i + 1;
	int number = 0; // number of k length
	int k = 1; // used to convert digits array to number
	// converting digits array to number
	for (int j = length - 1; j > -1; j--) {
		number += digits[j] * k;
		k *= 10;
	}
	// checking if all the digits are already in the number
	if (length == 9) {
		// if yes, then its beauty can only be 9
		if (beauty == 9)
			printf("%d\n", number);
		// number doest not exits
		else
			printf("-1\n");
		return 0;
	}
	// for every number whose digit sum is equal to beauty factor
	while (number < k) {
		int sum = number;
		// calculating digit sum until it becomes if single digit
		while (sum > 9)
			sum = digitsSum(sum);
			// if sum is equal to beauty factor, check if is a valid number or not
		if (sum == beauty) {
			int temp = number;
			int isSkip = 0;
			// checking if number contains 0 or repeated digits
			for (int i = 0; i < length; i++) {
				digits[i] = temp % 10;
				// if digit is 0, then move on to next number
				if (digits[i] == 0) {
					isSkip = 1;
					break;
				}
				temp /= 10;
				// checking for repeated digits
				for (int j = i - 1; j > -1; j--) {
					// if repeated digit, move on to next number
					if ((digits[i] == digits[j])) {
						isSkip = 1;
						break;
					}
				}
				// if 0 or repeated digit, move on to next number
				if (isSkip)
					break;
			}
			// if 0 or repeated digit, move on to next number
			if (isSkip) {
				// if beauty factor is more than sum, then next number is closer than 9 places
				if (beauty > sum)
					number += (beauty - sum);
				// if not, then next number is far than 9 places
				else 
					number += ((9 - sum) + beauty);
				continue;
			}
			printf("%d\n", number); // printing final result
			return 0;
		}
		// if beauty factor is more than sum, then next number is closer than 9 places
		if (beauty > sum)
			number += (beauty - sum);
		// if not, then next number is far than 9 places
		else 
			number += ((9 - sum) + beauty);
	}
	printf("-1\n"); // number doest not exits
	return 0;
}
