# You are conducting a contest at your college. This contest consits
# of two problems and n participants. You know the problem that a
# candidate will solve during the contest.
# You provide a balloon to a participate after he or she solves a
# problem. There are only green and purple-colored balloons
# available in a market. Each problem must have a ballon
# associated with it as a prize for solving that specific problem. You
# can distribute balloons to each participant by performing the
# following operation:
# 1. Use green-colored balloons for the first problem and purple-
#    colored balloons for the second problem.
# 2. Use purple-colored balloons for the first problem and green-
#    colored balloons for the second problem.
# You are the given the cost of each balloon and problems that each
# participant solve. Your task is to print the minimum price that you
# have to pay while purchasing balloons.
testCases = int(input())
# running for each test case
for i in range(0, testCases):
	problem1Win = 0
	problem2Win = 0
	price = input().split()
	greenPrice = int(price[0])
	purplePrice = int(price[1])
	participants = int(input())
	problem1 = [0] * participants
	problem2 = [0] * participants
	# inserting each participants wins in each problem
	for j in range(0, participants):
		status = input().split()
		problem1[j] = int(status[0])
		problem2[j] = int(status[1])
	# calculating total win for each problem
	for j in range(0, participants):
		problem1Win += problem1[j]
		problem2Win += problem2[j]
	# calculating minimum price for each problem
	if greenPrice < purplePrice:
		if problem1Win > problem2Win:
			totalPrice = (greenPrice * problem1Win) + (purplePrice * problem2Win)
		else:
			totalPrice = (greenPrice * problem2Win) + (purplePrice * problem1Win)
	else:
		if problem1Win > problem2Win:
			totalPrice = (purplePrice * problem1Win) + (greenPrice * problem2Win)
		else:
			totalPrice = (purplePrice * problem2Win) + (greenPrice * problem1Win)
	print(totalPrice)
