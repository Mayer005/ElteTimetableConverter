#include <iostream>
#include "Lesson.h"
#include "Serialize.h"


int main(int argc, char* argv[]){
    if (argc != 3 || std::string(argv[1]) != "csvtool") {
        std::cerr << "The use of the program is: serialize csvtool <filename>" << std::endl;
        return 1;
    }

    Serializer serializer;

    std::vector<Lesson> lessons;
    std::string filename = argv[2];

    lessons = serializer.deserializeFromTxtToLessons(filename);
    serializer.serializeLessonToCsV(lessons);

    return 0;
}

