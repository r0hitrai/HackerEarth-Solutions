/* It's 12 o'clock at midnight (00:00) and Simon cannot sleep!
   So he decided to stare at the clock on his wall until he falls asleep.
   He saw the clock's hands and got to thinking "How many times they'll pass each
   other until I fall asleep". Imagine that he fell asleep at hh:mm.
   Now you must figure out how many times clock's hands overlap from 00:00 to hh:mm
   (including 00:00 and hh:mm)
*/
#include<stdio.h>
int main() {
	int sleepHour, sleepMinute, overlap = 1, isOverlap = 1;
	double hourDegree = 0, minuteDegree = 0;
	scanf("%d:%d", &sleepHour, &sleepMinute);
	int totalMinutes = (sleepHour * 60) + sleepMinute;
	/* for every minute */
	for (int i = 0; i < totalMinutes; i++) {
		minuteDegree += 6;
		hourDegree += 0.5;
		/* if full lap, reset minute and overlap */
		if (minuteDegree == 360) {
			minuteDegree = 0;
			isOverlap = 0;
		}
		/* if full lap, reset hour */
		if (hourDegree == 360)
			hourDegree = 0;
		/* if overlap, increase number of overlap */
		if (minuteDegree >= hourDegree) {
			/* if not already overlaped */
			if (!isOverlap) {
				overlap++;
				isOverlap = 1;
			}
		}
	}
	printf("%d\n", overlap);
	return 0;
}
