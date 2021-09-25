# You are given an integer array A. Your task is to calculate the sum
# of absolute difference of indices of first and last occurrence for
# every integer that is present in array A.
# Formally, if element x occurs m times in the array at indices B1, B2,
# B3,...,Bm, then the answer for x will be Bm-B1 if array B is stored.
# You are required to calculate the sum of the answer for every such x
# that occurs in the array.
testCase = int(input()) # setting number of test cases
# calculating for every test case
for k in range(0, testCase):
	totalSum = 0
	size = int(input()) # setting size of array
	numbers = {x : x for x in range(0, size)} # array containing all numbers
	i = 0
	for number in input().split():
		numbers[i] = int(number)
		i += 1
	sortedNumbers = dict(sorted(numbers.items(), key = lambda item: item[1]))
	locationsList = list(sortedNumbers.keys())
	numbersList = list(sortedNumbers.values())
	i = 0
	# calculating total sum of every number's first and last occurence
	while i < size:
		# finding last occurence of current number
		for j in range(i, size):
			# for last number
			if j + 1 == size:
				totalSum += (locationsList[j] - locationsList[i]); # adding difference of last and first occurence of current number in sum
				i = j + 1; # setting current number to first occurence of next different number
				break
			# if current number is equal to next nubmer, then next iteration of loop
			if numbersList[i] == numbersList[j + 1]:
				continue
			totalSum += (locationsList[j] - locationsList[i]) # adding difference of last and first occurence of current number in sum
			i = j + 1 # setting current number to first occurence of next different number
			break
	print(totalSum) # printing final result
