# It's 12 o'clock at midnight (00:00) and Simon cannot sleep!
# So he decided to stare at the clock on his wall until he falls asleep.
# He saw the clock's hands and got to thinking "How many times they'll pass each
# other until I fall asleep". Imagine that he fell asleep at hh:mm.
# Now you must figure out how many times clock's hands overlap from 00:00 to hh:mm
# (including 00:00 and hh:mm)
overlap = 1
isOverlap = True
hourDegree = 0
minuteDegree = 0
time = input()
sleepHour = int(time.split(":")[0])
sleepMinute = int(time.split(":")[1])
totalMinutes = (sleepHour * 60) + sleepMinute
# for every minute
for i in range(0, totalMinutes):
	minuteDegree += 6
	hourDegree += 0.5
	# if full lap, reset minute and overlap
	if minuteDegree == 360:
		minuteDegree = 0
		isOverlap = False
	# if full lap, reset hour
	if hourDegree == 360:
		hourDegree = 0
	# if overlap, increase number of overlap
	if minuteDegree >= hourDegree:
		# if not already overlaped
		if not(isOverlap):
			overlap += 1
			isOverlap = True
print(overlap)
