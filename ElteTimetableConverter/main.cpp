#include <iostream>
#include "Lesson.h"
#include "Serialize.h"



/**
 * @brief Main function for the CSV tool.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Exit status.
 */
int main(int argc, char* argv[]){

    // Check if the correct number of arguments is provided and the first argument is "csvtool"
    if (argc != 3 || std::string(argv[1]) != "csvtool") {
        std::cerr << "The use of the program is: serialize csvtool <filename>" << std::endl;
        return 1;
    }

    Serializer serializer;

    std::vector<Lesson> lessons;
    std::string filename = argv[2];

    // Deserialize lessons from the provided file
    lessons = serializer.deserializeFromTxtToLessons(filename);

    // Serialize lessons to CSV format
    serializer.serializeLessonToCsV(lessons);

    return 0;
}

