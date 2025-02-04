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
	std::vector<Lesson> lessons;
	std::ifstream input(filename);
	std::string line;

	//Skip the first row.
	std::getline(input, line);
	std::string year;
	std::string month;
	std::string day;
	Lesson lesson;

	while(std::getline(input, line)) {
		if (line.empty()) {
			continue;
		}


		line.erase(std::remove(line.begin(), line.end(), ','), line.end());

		std::stringstream ss(line);

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
			std::string del;
			std::getline(ss, del, '\t');
			std::getline(ss, lesson.description, '\n');
		}
		else if (line.length() < 5) {
			continue;
		}
		else {
			std::string del;
			std::string add;
			std::getline(ss, del, '\t');
			std::getline(ss, lesson.location, '\t');
			std::getline(ss, add, '\n');

			lesson.description.append(": ");
			lesson.description.append(add);

			lessons.push_back(lesson);
			lesson.clear();
		}
	}

	return lessons;
}


void Serializer::serializeLessonToCsV(const std::vector<Lesson>& lessons) const {
	std::ofstream output("timetable.csv", std::ios::out | std::ios::binary);
	if (!output) {
		std::cerr << "The file timetable.csv (output file) can not be open" << std::endl;
		return;
	}


	output << "\xEF\xBB\xBF";

	output << "Subject,Start date,Start time,End Date,End Time,All Day Event,Description,Location" << std::endl;


	for (const Lesson& a : lessons) {
		output << a;
	}

	std::cout << "timetable.csv created succesfully." << std::endl;

	output.close();
}
