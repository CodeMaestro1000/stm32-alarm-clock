#include "time.h"


# define MAX_SECONDS_VAL 86400 // total number of seconds in a day

/*
Constructor for Time object.

Will validate that the passed value are within the accepted values before constructing
object
*/
Time::Time(unsigned int hour, unsigned int minute, unsigned int second){
    this->validate(hour, minute, second);
    this->total_seconds = (hour * 3600) + (minute * 60) + second;
}

/*
Validation function for user provided values
*/
bool Time::validate(unsigned int hour, unsigned int minute, unsigned int second){
    if (hour > 23)
        return false;
    if (minute > 59)
        return false;
    if (second > 59)
        return false;

    return true;
}

/*
Update time. Will be validate before the individual attributes are updated.

Implementation looks exactly like the constructor. We could use one func here but the author
has decided to let decouple these two functions.
*/
bool Time::setTime(int hour, int minute, int second) {
    bool is_valid = this->validate(hour, minute, second);
    if (!is_valid)
        return false;
    this->total_seconds = (hour * 3600) + (minute * 60) + second;
    return true;
}

/*
Print the time by sending to UART.
*/
char* Time::getTime(){
    int hours   = this->total_seconds / 3600;
    int minutes = (this->total_seconds % 3600) / 60;
    int seconds = this->total_seconds % 60;

    char *string_rep = this->string_rep;

    string_rep[0] = '0' + hours / 10;
    string_rep[1] = '0' + hours % 10;
    string_rep[2] = ':';
    string_rep[3] = '0' + minutes / 10;
    string_rep[4] = '0' + minutes % 10;
    string_rep[5] = ':';
    string_rep[6] = '0' + seconds / 10;
    string_rep[7] = '0' + seconds % 10;
    string_rep[8] = '\0';


    return string_rep;
}

/*
Overload the ++ (postfix) operator.

The int parameter is only a marker for the compiler and is never used, so it doesn't need a name
*/
Time& Time::operator++(int) {
    total_seconds = (total_seconds + 1) % MAX_SECONDS_VAL;
    return *this;  // reference to the updated object
}