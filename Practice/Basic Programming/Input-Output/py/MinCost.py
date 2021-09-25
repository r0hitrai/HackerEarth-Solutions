# You are given an array of numbers. Ai which contains positive as well as
# negative numbers. The cost of the array can be defined as C(X).
# C(x)=|A1+T1|+|A2+T2|+...+|An+Tn|, where T is
# the transfer array which contains N zeros initially.
# You need to minimize this cost. You can transfer value from one array
# element to another if and only if the distance between them is at most K.
# Also, transfer value can't be transferred further.
sum1 = 0
counter = 0
cost = 0
firstLine = input().split()
size = int(firstLine[0])
k = int(firstLine[1])
m = k
numbers = [0] * size
j = 0
# setting input values in numbers
for i in input().split():
	numbers[j] = int(i)
	j += 1
# for each value in numbers
for i in range(0, size):
	# if positive value, then increment counter and add value to sum
	if numbers[i] >= 0:
		counter += 1
		sum1 += numbers[i]
		m = k
	# if negative value, then
	else:
		# if it is first value in numbers, then print sum of all numbers
		if counter == 0:
			# calculating final cost
			for j in range(0, size):
				# if number is negative, then subtract
				if numbers[j] < 0:
					cost -= numbers[j]
				# if number is positive, then add
				else:
					cost += numbers[j]
			print(cost)
			exit()
		# if it is not the first value, then
		else:
			m -= 1
			if m < 0:
				sum1 -= numbers[i]
			else:
				sum1 += numbers[i]
# if number is negative, then subtract
if sum1 < 0:
	sum1 = 0 - sum1
print(sum1)
