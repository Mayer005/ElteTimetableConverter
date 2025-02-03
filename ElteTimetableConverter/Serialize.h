#ifndef SERIALIZE
#define SERIALIZE

#include <string>
#include <vector>
#include "Lesson.h"

bool ends_with(const std::string& str, const std::string& suffix);

class Serializer {
public:
	Serializer() {};

	std::vector<Lesson> deserializeFromTxtToLessons(const std::string& filename) const;
	void serializeToCsV();

};





#endif