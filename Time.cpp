#include "Time.h"
#include <iostream>
#include <string>
#include <ctype.h>

Time::Time()
{
	std::cin >> string_time;
	if (isalpha(string_time.back()))
	{
		ap = string_time.back();
		string_time.pop_back();
		int_time = std::stoi(string_time);
	}
	else
	{
		std::cout << "AM or PM? [a or p]: ";
		std::cin >> ap;
		int_time = std::stoi(string_time);
	}
	if (int_time < 1000 && int_time > 12)
	{
		hour = int_time;
		while (hour >= 10)
		{
			hour = hour / 10;
		}
	}
	else
	{
		switch (int_time)
		{
		case 0 ... 12:
			hour = int_time;
			break;
		case 1000 ... 1099:
			hour = 10;
			break;
		case 1100 ... 1199:
			hour = 11;
			break;
		case 1200 ... 1299:
			hour = 12;
			break;
		default:
			std::cout << "Invalid time." << std::endl;
			break;
		}
	}
	if (int_time <= 12)
	{
		minute = 0;
	}
	else
	{
		minute = int_time % 100;
	}
	if (ap == 'p' && hour != 12)
	{
		hour += 12;
	}
}

Time::Time(const Time &t, const Time &t2)
{
	hour = t2.hour - t.hour;
	minute = t2.minute - t.minute;
	if (minute < 0)
	{
		hour -= 1;
		minute += 60;
	}
}