/* Arpasland has surrounded by attackers. A truck enters the city. The driver
   claims the load is food and medicine from Iranians. Ali is one of the
   soldiers in Arpasland. He doubts about the truck, maybe it's from the
   siege. He knows that a tag is valid if the sum of every two consecutive
   digits of it is even and its letter is not a vowel. Determine if the tag of the
   truck is valid or not.
   We consider the letters "A", "E", "I", "O", "U", "Y" to be vowels for this
   problem.
*/
import java.util.*;
class AliHelp {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String tag;
		char[] VOWELS = {'A', 'E', 'I', 'O', 'U', 'Y'};
		tag = sc.next();
		// checking each character for validity
		for (int i = 0; i < tag.length()-1; i++) {
			// ignoring some places
			if (i == 1 || i == 5 || i == 6)
				continue;
			// chaecking if the letter is not a vowel
			if (i == 2) {
				// checking with every vowel
				for (int j = 0; j < VOWELS.length; j++) {
					// if vowel then invalid
					if(tag.charAt(i) == VOWELS[j]) {
						System.out.println("invalid");
						return;
					}
				}
			}
			// checking if every two consequetive digits sum is not even
			else if (((tag.charAt(i) - '0') + (tag.charAt(i+1) - '0')) % 2 != 0) {
				System.out.println("invalid");
				return;
			}
		}
		System.out.println("valid");
	}
}
