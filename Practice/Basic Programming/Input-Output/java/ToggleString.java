/* You have been given a String S consisting of uppercase and lowercase
   English alphabets. You need to change the case of each alphabet in this
   String. That is, all the uppercase letters should be converted to lowercase
   and all the lowercase letters should be converted to uppercase. You need to
   then print the resultant String to output.
*/
import java.util.*;
class ToggleString {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String string;
		string = sc.next();
		char[] result = new char[string.length()];
		// for every character in string
		for (int i = 0; i < string.length(); i++) {
			// if it is UPPERCASE, convert it to LOWERCASE
			if (string.charAt(i) > 64 && string.charAt(i) < 97)
				result[i] = Character.toLowerCase(string.charAt(i));
			// if it is LOWERCASE, convert it to UPPERCASE
			else
				result[i] = Character.toUpperCase(string.charAt(i));
		}
		System.out.println(result);
	}
}
