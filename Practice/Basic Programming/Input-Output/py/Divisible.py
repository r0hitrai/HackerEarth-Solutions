# You are given an array A of size N that contains integers. Here, N
# is an even number. You are required to perform the following
# operations:
# 1. Divide the array of numbers in two equal halves
#    Note: Here, two equal parts of a test case are created by
#    dividing the array into two equal parts.
# 2. Take the first digit of the numbers that are available in the
#    first half of the array (first 50% of the test case)
# 3. Take the last digit of the numbers that are available in the
#    second half of the array (second 50% of the code test case)
# 4. Generate a number by using the digits that have been
#    selected in the above steps.
# Your task is to determine whether the newly-generated number is
# divisible by 11.
number = 0
oddSum = 0
evenSum = 0
size = int(input())
numbers = [0] * size
j = 0
# inserting input numbers
for i in input().split():
	numbers[j] = int(i)
	j += 1
digits = [0] * size
mid = int(size / 2)
# getting first digit of first half of numbers
for i in range(0, mid):
	while numbers[i] > 9:
		numbers[i] = int(numbers[i] / 10)
	digits[i] = numbers[i]
# getting last digit of second half of numbers
for i in range(mid, size):
	digits[i] = numbers[i] % 10
# sum of odd place digits
for i in range(0, size, 2):
	oddSum += digits[i]
# sum of even place digits
for i in range(1, size, 2):
	evenSum += digits[i]
# checking if number is divisible by 11
if ((oddSum - evenSum) == 0) or ((oddSum - evenSum) % 11 == 0):
	print("OUI")
else:
	print("NON")
