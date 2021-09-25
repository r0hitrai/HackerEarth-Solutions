/* You are given two arrays a1, a2,...,an and b1, b2,...bn. In
   each step, you can set ai = ai - bi if ai >= bi. Determine the
   minimum number of steps that are required to make all a's equal. */
#include<stdio.h>
int main() {
    int size, steps = 0, temp, minIndex, isCommon = 0, noOfCommon = 0, noOfSubs = 1;
    scanf("%d", &size);
    int a[size], b[size];
    minIndex = size - 1;
    /* inserting values in array a */
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    /* inserting vlaues in array b */
    for (int i = 0; i < size; i++)
        scanf("%d", &b[i]);
    /* putting smallest value of a in tha last index */
	for (int j = 0; j < minIndex; j++) {
    	if (a[j + 1] >= a[j]) {
    		temp = a[j];
    		a[j] = a[j + 1];
    		a[j + 1] = temp;
    		temp = b[j];
    		b[j] = b[j + 1];
    		b[j + 1] = temp;
    	}
    }
    /* if b = 0 then no need to find subtraction */
    if (b[minIndex] != 0) {
    	temp = a[minIndex];
    	/* caculate number of subtraction values */
	   	while (temp > b[minIndex]) {
   			noOfSubs++;
   			temp -= b[minIndex];
   		}
    }
    int subs[noOfSubs];
    subs[0] = a[minIndex];
    /* store each subtraction value in an array */
    for (int i = 1; i < noOfSubs; i++) {
    	subs[i] = subs[i - 1] - b[minIndex];
    }
    int noOfCommons[noOfSubs], noOfSteps[noOfSubs];
    /* setting initial value of noOfCommons = 0 */
    for (int i = 0; i < noOfSubs; i++)
    	noOfCommons[i] = 0;
    /* setting initial value of noOfSteps = 0 */
    for (int i = 0; i < noOfSubs; i++)
    	noOfSteps[i] = 0;
	/* for each subs, calculate no fo commeons and steps */
   	for (int i = 0; i < noOfSubs; i++) {
   		steps = 0;
   		/* for each vlaue of a, calculate subtraction, commons and steps */
   		for (int j = 0; j < size; j++) {
   			temp = a[j];
   			isCommon = 0;
   			/* if a subtraction is in array, assign value to no of commons and steps */
			if (temp == subs[i]) {
				noOfCommons[i]++;
				noOfSteps[i] = steps;
				isCommon = 1;
   			}
   			/* if common found, check in next value of a */
   			if (isCommon)
   				continue;
			/* if first value is not common then return coz b = 0 won't change firsr value */
   			if (b[j] == 0) {
   				printf("-1\n");	
   				return 0;
   			}
	   		/* for each subtraction of a */
   			while (temp >= b[j]) {
   				steps++;
   				temp -= b[j];
				/* if a subtraction is in array, assign value to no of commons and steps */
				if (temp == subs[i]) {
					noOfCommons[i]++;
					noOfSteps[i] = steps;
					isCommon = 1;
					
   				}
   				/* if common found, check in next value of a */
   				if (isCommon)
   					break;
   			}
   		}
   	}
   	for (int i = 0; i < noOfSubs; i++) {
   		if (noOfCommons[i] == size) {
   			printf("%d\n", noOfSteps[i]);
   			return 0;
   		}
   	}
   	printf("-1\n");
    return 0;
}
