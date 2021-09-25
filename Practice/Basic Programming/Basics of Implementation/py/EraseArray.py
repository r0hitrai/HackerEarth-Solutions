# You are given a binary array A of N elements. The array consists of 0's
# and 1's. You can perform the following operations as many times as
# possible:
# - Select a subarray starting from the first index that is inversion-free
# and delete it.
# Determine the minimum number of operations to delete the entire
# array.
testCase = int(input())
# calculating for every test case
for i in range(0, testCase):
	operation = 0;
	inversion = 0;
	size = int(input())
	numbers = [int(i) for i in input().split()]
	# calculating total number of inversions
	for j in range(0, size - 1):
		if numbers[j] > numbers[j + 1]:
			inversion +=1
	operation = inversion + 1
	print(operation)
