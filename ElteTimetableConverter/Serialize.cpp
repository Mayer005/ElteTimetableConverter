#include "Lesson.h"
#include "Serialize.h"
#include <fstream>
#include <sstream>
#include <iostream>



/**
* @brief Checks if a string ends with a given suffix.
* @param str The string to check.
* @param suffix The suffix to compare.
* @return True if the string ends with the given suffix, false otherwise.
*/

bool ends_with(const std::string& str, const std::string& suffix) {
	if (str.length() < suffix.length()) {
		return false;
	}

	return (str.substr(str.length() - suffix.length()) == suffix);
}

/**
 * @brief Deserializes lesson data from a text file.
 * @param filename The name of the file containing lesson data.
 * @return A vector of Lesson objects parsed from the file.
 */
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

		//Remove every comma from the line.
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

/**
 * @brief Serializes a vector of Lesson objects to a CSV file.
 * @param lessons The vector of Lesson objects to be serialized.
 */
void Serializer::serializeLessonToCsV(const std::vector<Lesson>& lessons) const {
	std::ofstream output("timetable.csv", std::ios::out | std::ios::binary);
	if (!output) {
		std::cerr << "The file timetable.csv (output file) can not be open" << std::endl;
		return;
	}

	//write UTF-8 BOM for proper encoding
	output << "\xEF\xBB\xBF";

	//write the header of the csv file
	output << "Subject,Start date,Start time,End Date,End Time,All Day Event,Description,Location" << std::endl;

	//write lesson data
	for (const Lesson& a : lessons) {
		output << a;
	}

	std::cout << "timetable.csv created succesfully." << std::endl;

	output.close();
}
