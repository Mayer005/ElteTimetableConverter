#ifndef SERIALIZE
#define SERIALIZE

#include <string>

class Serializer {
public:
	void deserializeFromTxt(const std::string& filename);
	void serializeToCsV();

};





#endif