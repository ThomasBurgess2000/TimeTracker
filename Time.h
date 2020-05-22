#ifndef TIME_H_
#define TIME_H_

#include <string>

struct Time
{
	std::string string_time;
	int int_time, hour, minute;
	char ap;
	
	Time();
	Time(const Time &t, const Time &t2);
};

#endif