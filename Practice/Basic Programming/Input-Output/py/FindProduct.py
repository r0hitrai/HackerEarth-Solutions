# You have been given an array A of size N consisting of positive
# integers. You need to find and print the product of all the number in
# this array Modulo 1000000000 + 7.
size = int(input())
product = 1;
numbers = [0] * size
j = 0
# putting input in numbers
for i in input().split():
	numbers[j] = int(i)
	j += 1
# calculating of product of all numbers
for number in numbers:
	product = (product * number) % (1000000000 + 7);
print(product)
