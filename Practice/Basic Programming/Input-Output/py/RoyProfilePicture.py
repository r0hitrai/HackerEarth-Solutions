# Roy wants to change his profile picture on Facebook. Now Facebook has
# some restriction over the dimension of picture that we can upload.
# Minimum dimension of the picture can be L * L where L is the length of
# the side of square.
# Now Roy has N photos of varioud dimensions.
# Dimension of a photo is denoted as W * H
# where W - width of the photo and H - height of the photo.
# When any photo is uploaded following events may occur:
# 1. If any of the width or height is less than L, user is prompted to
#    upload another one. Print "UPLOAD ANOTHER" in this case.
# 2. If width and height, both are large enough and
# a. if the photo is already square then it is accepted. Print "ACCEPTED
#    in this case.
# b. else user is prompted to crop it. Print "CROP IT" in this case.
# Given L, N, W and H as input, print appropriate text as output.
length = int(input())
photosNo = int(input())
# veifying every picture
for i in range(0, photosNo):
	nextLine = input().split()
	width = int(nextLine[0])
	height = int(nextLine[1])
	# checking if any of width or height is lorger than length
	if width < length or height < length:
		print("UPLOAD ANOTHER")
	# checking of both width and height is same
	elif width == height:
		print("ACCEPTED")
	# if both width and height not same and bigger than width, then crop it
	else:
		print("CROP IT")
