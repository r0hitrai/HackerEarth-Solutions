/* It's 12 o'clock at midnight (00:00) and Simon cannot sleep!
   So he decided to stare at the clock on his wall until he falls asleep.
   He saw the clock's hands and got to thinking "How many times they'll pass each
   other until I fall asleep". Imagine that he fell asleep at hh:mm.
   Now you must figure out how many times clock's hands overlap from 00:00 to hh:mm
   (including 00:00 and hh:mm)
*/
import java.util.Scanner;
class SimonCannotSleep {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int sleepHour, sleepMinute, overlap = 1;
		boolean isOverlap = true;
		double hourDegree = 0, minuteDegree = 0;
		String time = sc.next();
		sleepHour = Integer.parseInt(time.split(":")[0]);
		sleepMinute = Integer.parseInt(time.split(":")[1]);
		int totalMinutes = (sleepHour * 60) + sleepMinute;
		// for every minute
		for (int i = 0; i < totalMinutes; i++) {
			minuteDegree += 6;
			hourDegree += 0.5;
			// if full lap, reset minute and overlap
			if (minuteDegree == 360) {
				minuteDegree = 0;
				isOverlap = false;
			}
			// if full lap, reset hour
			if (hourDegree == 360)
				hourDegree = 0;
			// if overlap, increase number of overlap
			if (minuteDegree >= hourDegree) {
				// if not already overlaped
				if (!isOverlap) {
					overlap++;
					isOverlap = true;
				}
			}
		}
		System.out.println(overlap);
    }
}
