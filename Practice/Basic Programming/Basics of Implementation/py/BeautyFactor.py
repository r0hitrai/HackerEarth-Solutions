# You are given a positive integer n. The beauty factor of a number is
# the sum of digits obtained till the obtained sum is a single digit.
# Example
# - Beauty factor of 1987 = 1+9+8+7 = 25 = 2+5 = 7
# - Beauty factor of 10 = 1+0 = 1
# You are given a beauty factor, b. Your task is to find a minimum
# number (n) of length k whose beauty factor is b.
# Here, the length of a number is defined as the number of digits a
# number has.
# Note: The digits of the number in the output must be distinct and 
# must be a positive integer.
# calculate sum of all digits in the number
def digitsSum(num):
	totalSum = 0;
	# taking last digint and adding in to the sum and removing it from number
	while num != 0:
		totalSum += num % 10
		num = int(num / 10)
	return totalSum
# main function
line = input().split()
beauty = int(line[0])
length = int(line[1])
digits = [0] * length # array of digits if k length
j = 0
# setting inital digits which are not 0 and not repeated
for i in range(0, length):
	digits[j] = i + 1
	j += 1
number = 0; # number of k length
k = 1; # used to convert digits array to number
# converting digits array to number
for j in range(length - 1, -1, -1):
	number += digits[j] * k
	k *= 10
# checking if all the digits are already in the number
if length == 9:
	# if yes, then its beauty can only be 9
	if beauty == 9:
		print(number)
	# number doest not exits
	else:
		print("-1")
	exit(0)
# for every number whose digit sum is equal to beauty factor
while number < k:
	totalSum = number
	# calculating digit sum until it becomes if single digit
	while totalSum > 9:
		totalSum = digitsSum(totalSum)
		# if sum is equal to beauty factor, check if is a valid number or not
	if totalSum == beauty:
		temp = number
		isSkip = False
		# checking if number contains 0 or repeated digits
		for i in range(0, length):
			digits[i] = temp % 10
			# if digit is 0, then move on to next number
			if digits[i] == 0:
				isSkip = True
				break
			temp = int(temp / 10)
			# checking for repeated digits
			for j in range(i - 1, -1, -1):
				# if repeated digit, move on to next number
				if (digits[i] == digits[j]):
					isSkip = True
					break
			# if 0 or repeated digit, move on to next number
			if isSkip:
				break
		# if 0 or repeated digit, move on to next number
		if isSkip:
			# if beauty factor is more than sum, then next number is closer than 9 places
			if beauty > totalSum:
				number += (beauty - totalSum)
			# if not, then next number is far than 9 places
			else:
				number += ((9 - totalSum) + beauty)
			continue
		print(number) # printing final result
		exit(0)
	# if beauty factor is more than sum, then next number is closer than 9 places
	if beauty > totalSum:
		number += (beauty - totalSum)
	# if not, then next number is far than 9 places
	else:
		number += ((9 - totalSum) + beauty)
print("-1") # number doest not exits
