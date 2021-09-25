/* Your program is to use the brute-force approach in order to find the
   Answer to life, the Universe, and Everything. More precisely... rewrite small
   numbers from input to output. Stop processing input after reading in the
   number 42. All numbers at input are integers of one or two digits.
*/
import java.util.*;
class LifeUniverseEverything {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int number;
		number = sc.nextInt();
		// print number while we don't get 42
		while (number != 42) {
			System.out.println(number);
			number = sc.nextInt();
		}
	}
}	
