/* You all have seen a seven segment display.
   Alice got a number written in seven segment format where each
   segment was creatted used a matchstick.
   Example, if Alice gets a number 123 so basically Alice used 12
   matchsticks for this number.
   Alice is wondering what is the numerically largest value that
   she can generate by using at most the matchsticks that she
   currently posses. Help Alice out by telling her that number.
*/
import java.util.*;
class SevenSegmentDisplay {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int testCases, matchsticks = 0, maxNumber, totalMatchsticks, i, j;
		String number;
		testCases = sc.nextInt();
		// running for each test case
		for (i = 0; i < testCases; i++) {
			totalMatchsticks = 0;
			number = sc.next();
			// calculating matchsticks for each digit of the number
			for (j = 0; j < number.length(); j++)  {
				/* setting matchsticks for currenr digit */
				switch (number.charAt(j)) {
					case '0':
						matchsticks = 6;
						break;
					case '1':
						matchsticks = 2;
						break;
					case '2':
						matchsticks = 5;
						break;
					case '3':
						matchsticks = 5;
						break;
					case '4':
						matchsticks = 4;
						break;
					case '5':
						matchsticks = 5;
						break;
					case '6':
						matchsticks = 6;
						break;
					case '7':
						matchsticks = 3;
						break;
					case '8':
						matchsticks = 7;
						break;
					case '9':
						matchsticks = 6;
						break;
					default:
						System.out.println("Unknown");
						break;
				}
				totalMatchsticks += matchsticks;
			}
			// if one stick left, then first digit will be 7
			if (totalMatchsticks % 2 == 1) {
				System.out.print("7");
				totalMatchsticks-=3;
			}
			// calculating maximum digit number
			for (j = 0; j < totalMatchsticks; j+=2)
				System.out.print("1");
			System.out.print("\n");
		}
	}
}
