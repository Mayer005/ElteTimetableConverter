#ifndef LESSON
#define LESSON


#include <string>
#include <iostream>

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
private:
	Date _startDate;
	Date _endDate;
	Time _startTime;
	Time _endTime;

	std::string _subject;
	const std::string _c_allDayEvent = "FALSE";
	std::string _description;
	std::string _location;


public:
	Lesson(Date startD, Date endD, Time startT, Time endT, std::string sub, std::string desc, std::string loc) : _startDate(startD), _endDate(endD), _startTime(startT),
		_endTime(endT), _subject(sub), _description(desc), _location(loc){}

	friend std::ostream& operator<<(std::ostream& os, Lesson& l);

};








#endif

