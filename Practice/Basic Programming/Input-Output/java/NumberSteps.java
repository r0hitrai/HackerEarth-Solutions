/* You are given two arrays a1, a2,...,an and b1, b2,...bn. In
   each step, you can set ai = ai - bi if ai >= bi. Determine the
   minimum number of steps that are required to make all a's equal.
*/
import java.util.*;
class NumberSteps {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
	    int size, steps = 0, temp, minIndex, noOfCommon = 0, noOfSubs = 1;
	    boolean isCommon = false;
	    size = sc.nextInt();
	    int[] a = new int[size];
	    int[] b = new int[size];
	    minIndex = size - 1;
	    // inserting values in array a
	    for (int i = 0; i < size; i++)
	        a[i] = sc.nextInt();
	    // inserting vlaues in array b
	    for (int i = 0; i < size; i++)
	        b[i] = sc.nextInt();
	    // putting smallest value of a in tha last index
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
	    // if b = 0 then no need to find subtraction
	    if (b[minIndex] != 0) {
	    	temp = a[minIndex];
	    	// caculate number of subtraction values
		   	while (temp > b[minIndex]) {
	   			noOfSubs++;
	   			temp -= b[minIndex];
	   		}
	    }
	    int[] subs = new int[noOfSubs];
	    subs[0] = a[minIndex];
	    // store each subtraction value in an array
	    for (int i = 1; i < noOfSubs; i++) {
	    	subs[i] = subs[i - 1] - b[minIndex];
	    }
	    int[] noOfCommons = new int[noOfSubs];
	    int[] noOfSteps = new int[noOfSubs];
	    // setting initial value of noOfCommons = 0
	    for (int i = 0; i < noOfSubs; i++)
	    	noOfCommons[i] = 0;
	    // setting initial value of noOfSteps = 0
	    for (int i = 0; i < noOfSubs; i++)
	    	noOfSteps[i] = 0;
		// for each subs, calculate no fo commeons and steps
	   	for (int i = 0; i < noOfSubs; i++) {
	   		steps = 0;
	   		// for each vlaue of a, calculate subtraction, commons and steps
	   		for (int j = 0; j < size; j++) {
	   			temp = a[j];
	   			isCommon = false;
	   			// if a subtraction is in array, assign value to no of commons and steps
				if (temp == subs[i]) {
					noOfCommons[i]++;
					noOfSteps[i] = steps;
					isCommon = true;
	   			}
	   			// if common found, check in next value of a
	   			if (isCommon)
	   				continue;
				// if first value is not common then return coz b = 0 won't change firsr value
	   			if (b[j] == 0) {
	   				System.out.println("-1");	
	   				return;
	   			}
		   		// for each subtraction of a
	   			while (temp >= b[j]) {
	   				steps++;
	   				temp -= b[j];
					// if a subtraction is in array, assign value to no of commons and steps
					if (temp == subs[i]) {
						noOfCommons[i]++;
						noOfSteps[i] = steps;
						isCommon = true;
	   				}
	   				// if common found, check in next value of a
	   				if (isCommon)
	   					break;
	   			}
	   		}
	   	}
	   	for (int i = 0; i < noOfSubs; i++) {
	   		if (noOfCommons[i] == size) {
	   			System.out.println(noOfSteps[i]);
	   			return;
	   		}
	   	}
	   	System.out.println("-1");
	}
}
