/* You are given a table with n rows amd m columns. Each cell is
   colored with white or black. Considering the shapes created by black
   cells, what is the maximum border of these shapes?
*/
#include<iostream>
using namespace std;
int main() {
	int noOfTests, rows, cols, border, maxBorderRowUp, maxBorderRowDown, maxBorder, tempBorder;
	cin >> noOfTests;
	// running for every test case
	for (int k = 0; k < noOfTests; k++) {
		border = maxBorderRowUp = maxBorderRowDown = maxBorder = tempBorder = 0;
		cin >> rows;
		cin >> cols;
		char table[rows][cols];
		// setting values of cells in table
		for (int i = 0; i < rows; i++)
			cin >> table[i];
		// calculating maximum border in roes from up
		// calculating border of first row
		for (int i = 0; i < cols; i++) {
			if (table[0][i] == '#')
				maxBorderRowUp++;
		}
		// calculating borders of remaining rows
		for (int i = 1; i < rows; i++) {
			border = 0;
			tempBorder = 0;
			// calculating border of current row
			for (int j = 0; j < cols; j++) {
				if (table[i][j] == '#' && table[i-1][j] == '.')
					tempBorder++;
				// saving current border to compare with next border in samw row
				else if (table[i][j] == '#' && table[i-1][j] == '#') {
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
            if (table[rows-1][i] == '#')
                maxBorderRowDown++;
        }
        // calculating and printing borders of each row
        for (int i = rows - 1; i >= 0; i--) {
            border = 0;
            tempBorder = 0;
            // calculating border of current row
            for ( int j = 0; j < cols; j++) {
                // increment border
                if (table[i][j] == '#' && table[i+1][j] == '.')
                    tempBorder++;
                // saving current border to compare with next border in same row
                else if (table[i][j] == '#' && table[i+1][j] == '#') {
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
        cout << maxBorder << "\n";
	}
	return 0;
}
