# While playing a mental math game, you realize that the number k is
# mathematically beautiful.
# You then realize that the number x can be mathematically beautiful if
# it is represented as a sum of a sequence where each element is a
# power of k and all the numbers in the sequence are different.
# Your task is to determine whether the number is mathematically
# beautiful.
# calculatiing neatest sum to number
def nearestSum(number, value, power):
	# if value power is more than number, then don't go further
	if power > number:
		return 0
	# if value power is less than or equal to number, then go to next power
	else:
		totalSum = nearestSum(number, value, power * value); # calling itself with next power
	# if next sum becomes more than number, then return sum without adding
	if (totalSum + power) > number:
		return totalSum
	# if next sum becomes less than or equal to number, then return next sum
	else:
		totalSum += power
		return totalSum

# main function
testCase = int(input()) # setting number of test cases
# for every test case
for i in range(0, testCase):
	line = input().split()
	number = int(line[0]) # setting x
	value = int(line[1]) # setting k
	result = nearestSum(number, value, value) # calling nearestSum()
	# if nearest sum is equal to or 1 less than number, then print YES
	if (result == number) or ((result + 1) == number):
		print("YES")
	# if nearest sum id not equal to nor 1 less than number, then print NO
	else:
		print("NO")
