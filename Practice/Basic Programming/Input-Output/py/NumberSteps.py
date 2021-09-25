# You are given two arrays a1, a2,...,an and b1, b2,...bn. In
# each step, you can set ai = ai - bi if ai >= bi. Determine the
# minimum number of steps that are required to make all a's equal.
isCommon = False
noOfCommon = 0
noOfSubs = 1
size = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
minIndex = size - 1
for j in range(0, minIndex):
   	if a[j + 1] >= a[j]:
   		temp = a[j]
   		a[j] = a[j + 1]
   		a[j + 1] = temp
   		temp = b[j]
   		b[j] = b[j + 1]
   		b[j + 1] = temp
# if b = 0 then no need to find subtraction
if b[minIndex] != 0:
	temp = a[minIndex]
	# caculate number of subtraction values
	while temp > b[minIndex]:
		noOfSubs += 1
		temp -= b[minIndex]
subs = [0] * noOfSubs
subs[0] = a[minIndex]
# store each subtraction value in an array
for i in range(1, noOfSubs):
   	subs[i] = subs[i - 1] - b[minIndex]
noOfCommons = [0] * noOfSubs
noOfSteps = [0] * noOfSubs
# for each subs, calculate no fo commeons and steps
for i in range(0, noOfSubs):
	steps = 0
	# for each vlaue of a, calculate subtraction, commons and steps
	for j in range(0, size):
		temp = a[j]
		isCommon = False
		# if a subtraction is in array, assign value to no of commons and steps
		if temp == subs[i]:
			noOfCommons[i] += 1
			noOfSteps[i] = steps
			isCommon = True
		# if common found, check in next value of a
		if isCommon:
			continue
		# if first value is not common then return coz b = 0 won't change firsr value
		if b[j] == 0:
			print("-1")
			exit()
		# for each subtraction of a
		while temp >= b[j]:
			steps += 1
			temp -= b[j]
			# if a subtraction is in array, assign value to no of commons and steps
			if temp == subs[i]:
				noOfCommons[i] += 1
				noOfSteps[i] = steps
				isCommon = True
			# if common found, check in next value of a
			if isCommon:
				break
	if noOfCommons[i] == size:
		print(noOfSteps[i])
		exit()
print("-1")
