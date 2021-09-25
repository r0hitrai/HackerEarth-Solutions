/* Let n be an integer. We define a function f(n) which returns the cube
   of sum of digits of n.
   You are given two integers n and k. You have to find the value of the
   integer that is returned when the function is recursively applied k
   times on n.
   Formally, you have to find the value of fk(n).
*/
#include<stdio.h>
/* function returns the cube of sum of digits of number */
double cubeSumDigits(long num, long time) {
	long digitsSum = 0;
	/* for every digit of number */
	while (num != 0) {
		digitsSum += num % 10; /* summing digits */
		num /= 10; /* removing last digit */
	}
	return (digitsSum * digitsSum * digitsSum); /* returning cube of sum of digits */
}

/* main function */
int main() {
	long testCase, number, times, result, temp, count;
	scanf("%ld", &testCase); /* setting number of test cases */
	/* for each test case */
	for (int i = 0; i < testCase; i++) {
		scanf("%ld%ld", &number, &times); /* setting n and k */
		temp = 0;
		count = 0;
		/* for k times */
		for (int j = 0; j < times; j++) {
			count++; /* number of times function has already called */
			result = cubeSumDigits(number, times); /* calling function cubeSumDigits() */
			/* if result is same as the number, no need to futher calculate */
			if (result == number)
				break;
			/* if result is repeating on 3rd interval, no need to furhter calculate*/
			if(result == temp) {
				count = count-3;/* go back 3rd interval */
				/* if repeated value is on 3rd interval */
     			if((times%2!=0 && count%2==0) || (times%2==0 && count%2!=0)) {
					result = temp;
				}
				/* if repeated value is on 2nd interval */
				else {
					result = number;
				}
				break;
			}
			temp = number; /* storing last 3rd interval */
			number = result; /* storing last 2nd interval */
		}
		printf("%ld\n", result); /* printing final result */
	}
	return 0;
}
