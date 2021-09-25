# You are required to enter a word that consists of x and y that
# denote the number of Zs and Os respectively. The input word is
# considered similor to word zoo if 2 * x = y.
# Determine if the entered word is similar to word zoo.
# For example, words such as zzoooo and zzzoooooo are similar
# to word zoo but not the words such as zzooo and zzzooooo.
noOfZ = 0
noOfO = 0
word = input()
# for every character in word
for i in word:
	# counting no of Zs
	if i == 'z':
		noOfZ += 1
	# counting no of Os
	elif i == 'o':
		noOfO += 1
# checking if no of Os are twice of that of Zs
if noOfO == 2 * noOfZ:
	print("Yes")
else:
	print("No")
