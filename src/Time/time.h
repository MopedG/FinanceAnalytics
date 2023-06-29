#include <QObject>

class Time
{
public:
    Time() = default;

    static int getCurrentDay();
    static int getCurrentMonth();
    static int getCurrentYear();
};
