# You have been given a String S consisting of uppercase and lowercase
# English alphabets. You need to change the case of each alphabet in this
# String. That is, all the uppercase letters should be converted to lowercase
# and all the lowercase letters should be converted to uppercase. You need to
# then print the resultant String to output.
# Nore: without using string's swapcase() method
string = input()
result = ['a'] * len(string)
# for every character in string
for i in range(0, len(string)):
	# if it is UPPERCASE, convert it to LOWERCASE
	if string[i].isupper():
		result[i] = string[i].lower()
	# if it is LOWERCASE, convert it to UPPERCASE
	else:
		result[i] = string[i].upper()
for i in result:
	print(i, end = "")
