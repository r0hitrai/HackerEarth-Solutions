# Arpasland has surrounded by attackers. A truck enters the city. The driver
# claims the load is food and medicine from Iranians. Ali is one of the
# soldiers in Arpasland. He doubts about the truck, maybe it's from the
# siege. He knows that a tag is valid if the sum of every two consecutive
# digits of it is even and its letter is not a vowel. Determine if the tag of the
# truck is valid or not.
# We consider the letters "A", "E", "I", "O", "U", "Y" to be vowels for this
# problem.
VOWELS = ['A', 'E', 'I', 'O', 'U', 'Y']
tag = input()
# checking each character for validity
for i in range(0, len(tag) - 1):
	# ignoring some places
	if i == 1 or i == 5 or i == 6:
		continue
	# chaecking if the letter is not a vowel
	if i == 2:
		# checking with every vowel
		for j in range(0, len(VOWELS)):
			# if vowel then invalid
			if tag[i] == VOWELS[j]:
				print("invalid")
				exit()
	# checking if every two consequetive digits sum is not even
	elif (int(tag[i]) + int(tag[i + 1])) % 2 != 0:
		print("invalid")
		exit()
print("valid")
