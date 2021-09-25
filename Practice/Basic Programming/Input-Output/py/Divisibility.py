# You are provided an array A of size N that contains non-negative
# integers. Your task is to determine whether the number that is
# formed by selecting the last digit of all the N numbers is divisble
# by 10.
# Note: View the sample explanation section for more clarification.
size = int(input())
numbers = [0] * size
j = 0
# inserting input non-integers in numbers
for i in input().split():
	numbers[j] = int(i)
	j += 1
# checking if last digit is 0, which will be divisible by 10
if numbers[size - 1] % 10 == 0:
	print("Yes")
else:
	print("No")
