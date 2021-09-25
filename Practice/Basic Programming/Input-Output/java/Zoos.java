/* You are required to enter a word that consists of x and y that
   denote the number of Zs and Os respectively. The input word is
   considered similor to word zoo if 2 * x = y.
   Determine if the entered word is similar to word zoo.
   For example, words such as zzoooo and zzzoooooo are similar
   to word zoo but not the words such as zzooo and zzzooooo.
*/
import java.util.*;
class Zoos {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int i, noOfZ = 0, noOfO = 0;
		String word = sc.next();
		// for every character in word
		for (i = 0; i < word.length(); i++) {
			// counting no of Zs
			if (word.charAt(i) == 'z')
				noOfZ++;
			// counting no of Os
			else if (word.charAt(i) == 'o')
				noOfO++;
		}
		// checking if no of Os are twice of that of Zs
		if (noOfO == 2 * noOfZ)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
