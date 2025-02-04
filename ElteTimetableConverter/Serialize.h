#ifndef SERIALIZE
#define SERIALIZE

#include <string>
#include <vector>
#include "Lesson.h"

/**
 * @brief Checks if a string ends with a given suffix.
 * @param str The string to check.
 * @param suffix The suffix to compare.
 * @return True if the string ends with the given suffix, false otherwise.
 */
bool ends_with(const std::string& str, const std::string& suffix);

/**
 * @class Serializer
 * @brief Handles serialization and deserialization of Lesson objects.
 */
class Serializer {
public:
    /**
     * @brief Deserializes lesson data from a text file.
     * @param filename The name of the file containing lesson data.
     * @return A vector of Lesson objects parsed from the file.
     */
    std::vector<Lesson> deserializeFromTxtToLessons(const std::string& filename) const;

    /**
     * @brief Serializes a vector of Lesson objects to a CSV file.
     * @param lessons The vector of Lesson objects to be serialized.
     */
    void serializeLessonToCsV(const std::vector<Lesson>& lessons) const;
};

#endif // SERIALIZE
