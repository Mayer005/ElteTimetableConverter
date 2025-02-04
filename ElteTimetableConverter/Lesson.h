#ifndef LESSON
#define LESSON

#include <string>
#include <iostream>

/**
 * @struct Date
 * @brief Represents a date with year, month, and day.
 */
struct Date {
    int year;  ///< Year of the date
    int month; ///< Month of the date
    int day;   ///< Day of the date

    /**
     * @brief Default constructor initializing date to invalid values (-1).
     */
    Date() : year(-1), month(-1), day(-1) {}

    /**
     * @brief Parameterized constructor.
     * @param y Year
     * @param m Month
     * @param d Day
     */
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    /**
     * @brief Overloaded stream insertion operator for Date.
     * @param os Output stream
     * @param d Date object
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, const Date& d) {
        os << d.day << "/" << d.month << "/" << d.year;
        return os;
    }
};

/**
 * @struct Lesson
 * @brief Represents a lesson with date, time, subject, and other details to help it convert into a csv file later.
 */
struct Lesson {
    Date startDate;       ///< Start date of the lesson
    Date endDate;         ///< End date of the lesson
    std::string startTime; ///< Start time of the lesson
    std::string endTime;   ///< End time of the lesson
    std::string subject;   ///< Subject of the lesson
    const std::string c_allDayEvent = "FALSE"; ///< Constant string indicating if it's an all-day event (None of them are)
    std::string description; ///< Description of the lesson
    std::string location;    ///< Location of the lesson

    /**
     * @brief Overloaded stream insertion operator for Lesson.
     * @param os Output stream
     * @param l Lesson object
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, const Lesson& l) {
        os << l.subject << "," << l.startDate << "," << l.startTime << ","
            << l.endDate << "," << l.endTime << "," << l.c_allDayEvent
            << "," << l.description << "," << l.location << std::endl;
        return os;
    }

    /**
     * @brief Clears the lesson data.
     */
    void clear();
};

#endif // LESSON
