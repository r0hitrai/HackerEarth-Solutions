# You are given a table with n rows amd m columns. Each cell is
# colored with white or black. Considering the shapes created by black
# cells, what is the maximum border of these shapes?
import array as arr
noOfTests = int(input())
# running for every test case
for k in  range(0, noOfTests):
	border = maxBorderRowUp = maxBorderRowDown = maxBorder = tempBorder = 0
	string = input().split()
	rows = int(string[0])
	cols = int(string[1])
	table = [0] * rows;
	# setting values of cells in table
	for i in range(0, rows):
		table[i] = input(); 
	# calculating maximum border in roes from up
	# calculating border of first row
	for i in range(0, cols):
		if table[0][i] == '#':
			maxBorderRowUp += 1
	# calculating borders of remaining rows
	for i in range(1,rows):
		border = 0
		tempBorder = 0
		# calculating border of current row
		for j in range(0, cols):
			if table[i][j] == '#' and table[i-1][j] == '.':
				tempBorder += 1
			# saving current border to compare with next border in samw row
			elif table[i][j] == '#' and table[i-1][j] == '#':
				if tempBorder > border:
					border = tempBorder
				tempBorder = 0
		# when there is no inner shape
		if border == 0:
			border = tempBorder
		# setting maximum border from current borders
		if border > maxBorderRowUp:
			maxBorderRowUp = border
	# calculating maximum border in rows from downside
	# calculating border of last row
	for i in range(0, cols):
		if table[rows-1][i] == '#':
			maxBorderRowDown += 1
	# calculating and printing borders of each row
	for i in range(rows-2, -1, -1):
		border = 0
		tempBorder = 0
		# calculating border of current row
		for j in range(0, cols):
			# increment border
			if table[i][j] == '#' and table[i+1][j] == '.':
				tempBorder += 1
			# saving current border to compare with next border in same row
			elif table[i][j] == '#' and table[i+1][j] == '#':
				if tempBorder > border:
					border = tempBorder
				tempBorder = 0
		# when there is no inner shape
		if border == 0:
			border = tempBorder
		# setting maximum border from current borders
		if border > maxBorderRowDown:
			maxBorderRowDown = border
	# setting maximum border from up
	if maxBorderRowUp > maxBorderRowDown:
		maxBorder = maxBorderRowUp
	# setting maximum border from down
	else:
		maxBorder = maxBorderRowDown
	print(maxBorder)
