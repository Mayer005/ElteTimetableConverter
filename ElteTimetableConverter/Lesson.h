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

	friend std::ostream& operator<<(std::ostream& os, const Date& d) {
		os << d.day << "/" << d.month << "/" << d.year;
		return os;
	}

};


struct Lesson {
	Date startDate;
	Date endDate;
	std::string startTime;
	std::string endTime;
	std::string subject;
	const std::string c_allDayEvent = "FALSE";
	std::string description;
	std::string location;

	friend std::ostream& operator<<(std::ostream& os, Lesson& l) {
		os << l.subject << "," << l.startDate << "," << l.startTime << "," << l.endDate << "," << l.endTime << "," << l.c_allDayEvent << "," << l.description << "," << l.location << std::endl;
		return os;
	}

	void clear();

};








#endif

