#include "Lesson.h"

void Lesson::clear() {
	this->description.clear();
	this->endDate = Date();
	this->endTime.clear();
	this->location.clear();
	this->startDate = Date();
	this->startTime.clear();
	this->subject.clear();
}