#include "time.h"
#include <chrono>

int Time::getMonth()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int month = localTime.tm_mon + 1;
    return month;
}

int Time::getYear()
{
    auto currentTime  = std::chrono::system_clock::now();
    std::time_t timeT  = std::chrono::system_clock::to_time_t(currentTime);
    std::tm localTime = *std::localtime(&timeT);
    int year = localTime.tm_year + 1900;
    return year;
}
