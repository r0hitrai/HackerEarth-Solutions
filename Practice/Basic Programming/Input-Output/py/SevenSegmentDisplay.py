# You all have seen a seven segment display.
# Alice got a number written in seven segment format where each
# segment was creatted used a matchstick.
# Example, if Alice gets a number 123 so basically Alice used 12
# matchsticks for this number.
# Alice is wondering what is the numerically largest value that
# she can generate by using at most the matchsticks that she
# currently posses. Help Alice out by telling her that number.
def switch(arg):
	switcher = {
		'0' : 6,
		'1' : 2,
		'2' : 5,
		'3' : 5,
		'4' : 4,
		'5' : 5,
		'6' : 6,
		'7' : 3,
		'8' : 7,
		'9' : 6,
	}
	return switcher[arg]
testCases = int(input())
# running for each test case
for i in range(0, testCases):
	totalMatchsticks = 0
	number = input()
	# calculating matchsticks for each digit of the number
	for j in number:
		# setting matchsticks for currenr digit
		matchsticks = switch(j)
		totalMatchsticks += matchsticks
	# if one stick left, then first digit will be 7
	if totalMatchsticks % 2 == 1:
		print("7", end = "")
		totalMatchsticks-=3
	# calculating maximum digit number
	for j in range(0, totalMatchsticks, 2):
		print("1", end = "")
	print()
