/* You are given a table with n rows amd m columns. Each cell is
   colored with white or black. Considering the shapes created by black
   cells, what is the maximum border of these shapes?
*/
import java.util.*;
class MaxBorders {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int noOfTests, rows, cols, border, maxBorderRowUp, maxBorderRowDown, maxBorder, tempBorder;
		noOfTests = sc.nextInt();
		// running for every test case
		for (int k = 0; k < noOfTests; k++) {
			border = maxBorderRowUp = maxBorderRowDown = maxBorder = tempBorder = 0;
			rows = sc.nextInt();
			cols = sc.nextInt();
			String[] table = new String[rows];
			// setting values of cells in table
			for (int i = 0; i < rows; i++)
				table[i] = sc.next();
			// calculating maximum border in roes from up
			// calculating border of first row
			for (int i = 0; i < cols; i++) {
				if (table[0].charAt(i) == '#')
					maxBorderRowUp++;
			}
			// calculating borders of remaining rows
			for (int i = 1; i < rows; i++) {
				border = 0;
				tempBorder = 0;
				// calculating border of current row
				for (int j = 0; j < cols; j++) {
					if (table[i].charAt(j) == '#' && table[i-1].charAt(j) == '.')
						tempBorder++;
					// saving current border to compare with next border in samw row
					else if (table[i].charAt(j) == '#' && table[i-1].charAt(j) == '#') {
						if (tempBorder > border)
							border = tempBorder;
						tempBorder = 0;
					}
				}
				// when there is no inner shape
				if (border == 0)
					border = tempBorder;
				// setting maximum border from current borders
				if (border > maxBorderRowUp)
					maxBorderRowUp = border;
			}
			// calculating maximum border in rows from downside
			// calculating border of last row
			for (int i = 0; i < cols; i++) {
    	        if (table[rows-1].charAt(i) == '#')
    	            maxBorderRowDown++;
    	    }
    	    // calculating and printing borders of each row
    	    for (int i = rows-2; i >= 0; i--) {
    	        border = 0;
    	        tempBorder = 0;
    	        // calculating border of current row
    	        for ( int j = 0; j < cols; j++) {
    	            // increment border
    	            if (table[i].charAt(j) == '#' && table[i+1].charAt(j) == '.')
    	                tempBorder++;
    	            // saving current border to compare with next border in same row
    	            else if (table[i].charAt(j) == '#' && table[i+1].charAt(j) == '#') {
    	                if (tempBorder > border)
    	                    border = tempBorder;
    	                tempBorder = 0;
    	            }
    	        }
    	        // when there is no inner shape
    	        if (border == 0)
    	            border = tempBorder;
    	        // setting maximum border from current borders
    	        if (border > maxBorderRowDown)
    	            maxBorderRowDown = border;
    	    }
    	    // setting maximum border from up
    	    if (maxBorderRowUp > maxBorderRowDown)
    	        maxBorder = maxBorderRowUp;
    	    // setting maximum border from down
    	    else
    	        maxBorder = maxBorderRowDown;
    	    System.out.println(maxBorder);
		}
	}
}
