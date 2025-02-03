#include "Lesson.h"

std::ostream& operator<<(std::ostream& os, Lesson& l) {
	os << l._subject << "," << l._startDate << "," << l._startTime << "," << l._endDate << "," << l._endTime << "," << l._allDayEvent << 
}