/* You have been given a String S. You need to find and print whether this
   string is a palindrome or not. If yes, print "YES", else print
   "NO".
*/
import java.util.*;
class PalindromicString {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int front, back;
		String string;
		string = sc.next();
		int length = string.length();
		front = 0;
		back = length - 1;
		// checking for palindrome
		while (front < back) {
			// if alphabet id not same, then not a palindrome
			if (string.charAt(front) != string.charAt(back)) {
				System.out.println("NO");
				return;
			}
			front++;
			back--;
		}
		System.out.println("YES");
	}
}
