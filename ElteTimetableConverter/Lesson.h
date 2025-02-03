#ifndef LESSON
#define LESSON

struct Date {
	int year;
	int month;
	int day;

	Date() : year(-1), month(-1), day(-1) {}
	Date(int y, int m, int d) : year(y), month(m), day(d) {}

};

struct Time {
	int hours;
	int minutes;

	Time() : hours(-1), minutes(-1) {}
	Time(int h, int m) : hours(h), minutes(m) {}
};


class Lesson {
public:
	Date date;
};








#endif

