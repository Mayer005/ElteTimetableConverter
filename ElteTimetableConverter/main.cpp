#include <iostream>
#include "Lesson.h"
#include "Serialize.h"


int main(int argc, char* argv[]){
    if (argc != 2) {
        std::cerr << "The use of the program is: csvtool <filename>" << std::endl;
    }

    Serializer serializer;

    std::vector<Lesson> lessons;
    std::string filename = argv[1];

    lessons = serializer.deserializeFromTxtToLessons(filename);
    serializer.serializeLessonToCsV(lessons);


}

