#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

//Класс время заплыва: минуты, секунды, сантисекунды (min = 60 sec; sec = 100 csec)
class Time
{
private:
	unsigned int min;
	unsigned int sec;
	unsigned int csec;

	friend void normalize(Time& m);
public:
	Time();
	Time(int a, int b = 0, int c = 0);
	~Time() {};
	Time(const Time& m);

	void operator=(const Time& m);
	Time operator+(const Time& m) const;
	Time operator-(const Time& m) const;
	Time operator*(const int n) const;
	Time operator/(const int n) const;
	Time operator+=(const Time& m);
	Time operator-=(const Time& m);
	Time operator*=(const int n);
	Time operator/=(const int n);
	bool operator==(const Time& m) const;
	bool operator!=(const Time& m) const;
	bool operator>(const Time& m) const;
	bool operator>=(const Time& m) const;
	bool operator<(const Time& m) const;
	bool operator<=(const Time& m) const;
	friend ostream& operator<<(ostream& out, const Time& m);
	friend istream& operator>>(istream& in, Time& m);
};