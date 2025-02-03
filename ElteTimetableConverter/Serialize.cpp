#include "Lesson.h"
#include "Serialize.h"
#include <fstream>
#include <sstream>
#include <iostream>


bool ends_with(const std::string& str, const std::string& suffix) {
	if (str.length() < suffix.length()) {
		return false;
	}

	return (str.substr(str.length() - suffix.length()) == suffix);
}


std::vector<Lesson> Serializer::deserializeFromTxtToLessons(const std::string& filename) const {
	std::vector<Lesson> Lessons;
	std::ifstream input(filename);
	std::string line;

	//Skip the first row.
	std::getline(input, line);


	std::string year;
	std::string month;
	std::string day;

	while(std::getline(input, line)) {
		if (line.empty()) {
			continue;
		}

		std::stringstream ss(line);
		Lesson lesson;

		if (ends_with(line, "(BSc)")) {
			std::getline(ss, year, '.');
			lesson.startDate.year = std::stoi(year);
			lesson.endDate.year = std::stoi(year);

			std::getline(ss, month, '.');
			lesson.startDate.month = std::stoi(month);
			lesson.endDate.month = std::stoi(month);

			std::getline(ss, day, '\t');
			lesson.startDate.day = std::stoi(day);
			lesson.endDate.day = std::stoi(day);

			std::getline(ss, lesson.startTime, '-');
			std::getline(ss, lesson.endTime, '\t');

			std::getline(ss, lesson.subject, '\n');
		}
		else if ((line.rfind("Seminar") != std::string::npos) || (line.rfind("Lecture") != std::string::npos)) {

		}
		


	}

	return Lessons;
}
