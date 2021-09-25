# You are given an array A of N elements. Now you need to choose the
# best index of this array A. An index of the array is called best if the
# special sum of this index is maximum across the special sum of the
# other indices.
# To calculate the special sum for any index i, you pick the first element
# that is A[i] and add it to your sum. Now you pick next two elements i.e.
# A[i+1] and A[i+2] and add both of them to your sum. Now you
# will pick the next 3 elements and this continues till the index for which
# it is possible to pick the elements.
# Find the best index and in the output print its corresponding special
# sum. Note that there may be more than one best indices but you need
# to only print the maximum special sum.
seq = 2
totalSum = 0
k = 0
maxSum = -1000000000;
size = int(input())
numbers = [0] * size
sums = [0] * (size + 1)
j = 0
# putting values in numbers and their cumulative sum in sums
for i in input().split():
	numbers[j] = int(i)
	sums[j + 1] = sums[j] + numbers[j]
	j += 1
# calculating maximum special sum among all numbers
for i in range(size - 1, -1, -1):
	sumValue = sums[size] - sums[i];
	start = size - k
	# subtracting last pair of numbers which are not matching the sequence
	for j in range(start, size):
		sumValue -= numbers[j]
	# setting maximum special sum
	if sumValue > maxSum:
		maxSum = sumValue
	k += 1
	# restting last pair sequence value
	if k == seq:
		k = 0
		seq += 1
print(maxSum)
