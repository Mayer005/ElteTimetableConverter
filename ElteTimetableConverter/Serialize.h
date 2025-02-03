#ifndef SERIALIZE
#define SERIALIZE

#include <string>
#include <vector>
#include "Lesson.h"

class Serializer {
public:
	Serializer() {};

	void deserializeFromTxtToLessons(const std::string& filename, std::vector<Lesson>);
	void serializeToCsV();

};





#endif