#include "time.h"
#include <chrono>

int Time::getCurrentDay()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int day = localTime.tm_mday;
    return day;
}

int Time::getCurrentMonth()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int month = localTime.tm_mon + 1;
    return month;
}

int Time::getCurrentYear()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int year = localTime.tm_year + 1900;
    return year;
}

QString Time::getCurrentDate()
{
    return QString::number(getCurrentDay()) + "." + QString::number(getCurrentMonth());
}
