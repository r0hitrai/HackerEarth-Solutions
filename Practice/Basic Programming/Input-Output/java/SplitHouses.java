/* You live in a village. The village can be represented as a line that
   contains n grids. Each grid can be denoted as a house that is
   marked as H or a blank space that is marked as ..
   A person lives in each house. A person can move to a grid if it is
   adjacent to that person. Therefore, the grid must be present on the
   left and right side of that person.
   Now, you are required to put some fences that can be marked as 
   B on some blank spaces so that the village can be divided into
   several pieces. A person cannot walk past a fence but can walk
   through a house.
   You are required to divide the house based on the following rules:
   - A person cannot reach a house that does not belong to that
     specific person.
   - The number of grids each person can reach is the same and
     it includes the grid in which the house is situated.
   - In order to show that you are enthusiastic and if there are
     many answers, ther you are required to point the one where
     most fences are placed.
   Your task is to decide whether there is a possible solution. Print
   the possible solution.
*/
import java.util.*;
class SplitHouses {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int noOfGrids = sc.nextInt();
		String village = sc.next();
		char[] result = new char[noOfGrids];
		// if two houses are together, then no possible answer
		for (int i = 0; i < noOfGrids - 1; i++) {
			if (village.charAt(i) == 'H' && village.charAt(i+1) == 'H') {
				System.out.println("NO");
				return;
			}
		}
		// setting all blank spaces as fences
		for (int i = 0; i < noOfGrids; i++) {
			if (village.charAt(i) == '.')
				result[i] = 'B';
			else
				result[i] = village.charAt(i);
		}
		System.out.println("YES");
		for (int i = 0; i < noOfGrids; i++)
			System.out.print(result[i]);
	}
}
