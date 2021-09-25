/* Roy wants to change his profile picture on Facebook. Now Facebook has
   some restriction over the dimension of picture that we can upload.
   Minimum dimension of the picture can be L * L where L is the length of
   the side of square.
   Now Roy has N photos of varioud dimensions.
   Dimension of a photo is denoted as W * H
   where W - width of the photo and H - height of the photo.
   When any photo is uploaded following events may occur:
   1. If any of the width or height is less than L, user is prompted to
      upload another one. Print "UPLOAD ANOTHER" in this case.
   2. If width and height, both are large enough and
   a. if the photo is already square then it is accepted. Print "ACCEPTED
      in this case.
   b. else user is prompted to crop it. Print "CROP IT" in this case.
   Given L, N, W and H as input, print appropriate text as output.
*/
import java.util.*;
class RoyProfilePicture {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int length, photosNo, width, height;
		length = sc.nextInt(); 
		photosNo = sc.nextInt();
		// veifying every picture
		for (int i = 0; i < photosNo; i++) {
			width = sc.nextInt();
			height = sc.nextInt();
			// checking if any of width or height is lorger than length
			if (width < length || height < length)
				System.out.println("UPLOAD ANOTHER");
			// checking of both width and height is same
			else if (width == height)
				System.out.println("ACCEPTED");
			// if both width and height not same and bigger than width, then crop it
			else
				System.out.println("CROP IT");
		}
	}
}
