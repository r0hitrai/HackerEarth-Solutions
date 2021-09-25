# You have been given 3 integers - l, r and k. Find how many numbers
# between l anr r (both includive) are divisible by K. You do not need to print
# these numbers, you can just have to find their count.
dividendNo = 0
firstLine = input().split()
start = int(firstLine[0])
end = int(firstLine[1])
divisor = int(firstLine[2])
# checking for every number between start and end inclusovely
for i in range(start, end + 1):
	# counting divisible numbers
	if i % divisor == 0:
		dividendNo += 1
print(dividendNo)
