#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <iterator>
#include "Time.h"

using namespace std;

double stars_time(const Time &t)
{
	double temp = t.minute / 60.0 + t.hour;
	temp = round(temp*10)/10;
	return temp;
}

int main ()
{
	map<string, double> tasks;
	char user_choice = 'y';
	while (user_choice != 'n')
	{
		string task_name;
		cout << "Task name: ";
		cin >> task_name;
		cout << "Time begin: ";
		Time begin;
		cout << "Time end: ";
		Time end;
		Time difference(begin, end);
		double stars_total = stars_time(difference);
		try
		{
			tasks.at(task_name);
		}
		catch (const out_of_range& oor)
		{
			cout << "Task created!" << endl;
			tasks.insert(pair<string, double>(task_name,stars_total));
			stars_total = 0;
		}
		stars_total = stars_total + tasks.at(task_name);
		tasks.erase(task_name);
		tasks.insert(pair<string, double>(task_name, stars_total));
		
		cout << "Time for " << task_name << ": " << tasks.at(task_name) << endl << endl;
		cout << "Enter more? (y/n): ";
		cin >> user_choice;
	}
	map<string,double>::iterator it = tasks.begin();
	double total_time;
	cout << endl << endl;
	while (it != tasks.end())
	{
		cout << it->first << ": " << it->second << endl;
		total_time += it->second;
		it++;
	}
	cout << "TOTAL: " << total_time << endl;
	cin >> user_choice;
}