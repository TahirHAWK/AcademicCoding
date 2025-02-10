/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

enum timeStatus isTimeValid(struct time time);
struct time timeFromSec(int seconds);
struct time timePeriod(struct time t1, struct time t2);



enum timeStatus {
	TIME_INVALID,
	TIME_OK
};

struct time {
	unsigned int hours, minutes, seconds;

};


int main() {
	printf("Valid time : 1\n");
	printf("Invalid times : 0 0 0 0 0 0 \n");
	printf("Initialize from seconds since midnight:\n");

	return 0;
}

enum timeStatus isTimeValid(struct time time) {
	if (time.hours > 24 || time.hours < 0) {
		return TIME_INVALID;
	} else if(time.minutes > 60 || time.minutes < 0)
}


struct time timeFromSec(unsigned int seconds) {
	unsigned int hours = (seconds / 3600);
	unsigned int minutes = (seconds % 3600) / 60;
	unsigned int seconds = (seconds % 60);

	struct time tx = {hours, minutes, seconds};
	return tx;
}

struct time timePeriod(struct time t1, struct time t2) {

}
*/


/* Code done by the ultimate Tonmoy bruder
	//Exercise 80

struct Time {
	int hours, minutes, seconds;
};

enum timeStatus isTimeValid(struct Time t);

enum timeStatus {
	TIME_INVALID,
	TIME_OK
};

struct Time timeFromSec(int sec);
struct Time timePeriod(struct Time t1, struct Time t2);

int main()
{
	int sec;
	scanf("%d", &sec);

	struct Time time = timeFromSec(sec);
	int validation = isTimeValid(time);

	printf("Valid Time : %d\n", validation);

	printf("Initialize from seconds since midnight :\n");
	printf("%d sec => %02d : %02d : %02d\n",sec, time.hours, time.minutes, time.seconds);

	printf("\nPeriods :\n");
	struct Time t0 = { 9, 24, 16 };
	struct Time t1 = { 9, 25, 21 };
	struct Time t2 = { 8, 01, 00 };

	printf("t0 :  %02d : %02d : %02d\n",t0.hours, t0.minutes, t0.seconds);
	printf("t1 :  %02d : %02d : %02d\n", t1.hours, t1.minutes, t1.seconds);
	printf("t2 :  %02d : %02d : %02d\n", t2.hours, t2.minutes, t2.seconds);

	struct Time p1 = timePeriod(t0, t1);
	struct Time p2 = timePeriod(t0, t2);

	printf("Period with t0 and t1 : %02d: %02d : %02d\n", p1.hours, p1.minutes, p1.seconds);
	printf("Period with t0 and t2 : %02d: %02d : %02d\n", p2.hours, p2.minutes, p2.seconds);


}

struct Time timeFromSec(int sec)
{
	struct Time t;
	t.hours = (sec / 3600);
	t.minutes = ((sec % 3600) / 60);
	t.seconds = (sec % 60);

	return t;
}

struct Time timePeriod(struct Time t1, struct Time t2)
{
	struct Time t;
	if (t1.hours > t2.hours)
	{
		t.hours = t1.hours - t2.hours;
		t.minutes = t1.minutes - t2.minutes;
		t.seconds = t1.seconds - t2.seconds;
	}
	else {
		t.hours = t2.hours - t1.hours;
		t.minutes = t2.minutes - t1.minutes;
		t.seconds = t2.seconds - t1.seconds;
	}

	return t;
}


enum timeStatus isTimeValid(struct Time t)
{
	if (t.hours >= 0 && t.hours < 24 && t.minutes >= 0 && t.minutes < 60 && t.seconds >= 0 && t.seconds < 60)
	{
		return TIME_OK;
	}
	else
		return TIME_INVALID;
}
*/