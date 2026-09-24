#include <stdexcept>

class Time {
    private:
        unsigned int total_seconds = 0; // between 0 and 86399
        char string_rep[9] = "00:00:00"; // 8 chars for time. Last char for EOS ('/0') rep

        bool validate(unsigned int hour, unsigned int minute, unsigned int second);

    public:
        Time(unsigned int hour, unsigned int minute, unsigned int second);
        Time() = default; // will set 

        bool setTime(int hour, int minute, int second);
        char* getTime();

        Time& operator++(int);
};