# You have been given a positive integer N. You need to find and print the
# Factorial of this number. The factorial of a positive integer N refers to the
# product of all number in the range from 1 to N.
factorial = 1
number = int(input())
# calculating factorial of the number
for i in range(1, number + 1):
	factorial *= i
print(factorial)
