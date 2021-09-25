# You have been given a String S. You need to find and print whether this
# string is a palindrome or not. If yes, print "YES", else print
# "NO".
string = input()
length = len(string)
front = 0
back = length - 1
# checking for palindrome
while front < back:
	# if alphabet id not same, then not a palindrome
	if string[front] != string[back]:
		print("NO")
		exit()
	front += 1
	back -= 1
print("YES")
