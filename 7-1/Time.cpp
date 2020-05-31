#include "Time.h"

void normalize(Time& m)
{
	m.min += m.sec / 60 + m.csec / 6000;
	m.sec = m.sec % 60 + (m.csec / 100) % 60;
	m.csec %= 100;
	if (m.sec >= 60)
	{
		m.min += m.sec / 60;
		m.sec %= 60;
	}
}

Time::Time() :
	min(0),
	sec(0),
	csec(0) {}

Time::Time(int a, int b, int c) :
	min(a),
	sec(b),
	csec(c)
{
	normalize(*this);
}

Time::Time(const Time& m) :
	min(m.min),
	sec(m.sec),
	csec(m.csec) {}

void Time::operator=(const Time& m)
{
	min = m.min;
	sec = m.sec;
	csec = m.csec;
}

Time Time::operator+(const Time& m) const
{
	return Time(min + m.min, sec + m.sec, csec + m.csec);
}

Time Time::operator-(const Time& m) const
{
	return Time(min - m.min, sec - m.sec, csec - m.csec);
}

Time Time::operator*(const int n) const
{
	return Time(min * n, sec * n, csec * n);
}

Time Time::operator/(const int n) const
{
	double t;
	return Time(min / n, sec / n, csec / n + (modf(1.0 * min / n, &t) * 6000) + (modf(1.0 * sec / n, &t) * 100));
}

Time Time::operator+=(const Time& m)
{
	min += m.min;
	sec += m.sec;
	csec += m.csec;
	normalize(*this);
	return Time(*this);
}

Time Time::operator-=(const Time& m)
{
	min -= m.min;
	sec -= m.sec;
	csec -= m.csec;
	normalize(*this);
	return Time(*this);
}

Time Time::operator*=(const int n)
{
	min *= n;
	sec *= n;
	csec *= n;
	normalize(*this);
	return Time(*this);
}

Time Time::operator/=(const int n)
{
	double t;
	csec /= n;
	csec += (modf(1.0 * min / n, &t) * 6000) + (modf(1.0 * sec / n, &t) * 100);
	min /= n;
	sec /= n;
	normalize(*this);
	return Time(*this);
}

bool Time::operator==(const Time& m) const
{
	return(min == m.min && sec == m.sec && csec == m.csec);
}

bool Time::operator!=(const Time& m) const
{
	return(min != m.min || sec != m.sec || csec != m.csec);
}

bool Time::operator>(const Time& m) const
{
	return(min * 6000 + sec * 60 + csec > m.min * 6000 + m.sec * 60 + m.csec);
}

bool Time::operator>=(const Time& m) const
{
	return(min * 6000 + sec * 60 + csec >= m.min * 6000 + m.sec * 60 + m.csec);
}

bool Time::operator<(const Time& m) const
{
	return(min * 6000 + sec * 60 + csec < m.min * 6000 + m.sec * 60 + m.csec);
}

bool Time::operator<=(const Time& m) const
{
	return(min * 6000 + sec * 60 + csec <= m.min * 6000 + m.sec * 60 + m.csec);
}

ostream& operator<<(ostream& out, const Time& m)
{
	out << m.min << " min " << m.sec << " sec " << m.csec << " msec";
	return out;
}

istream& operator>>(istream& in, Time& m)
{
	in >> m.min;
	in >> m.sec;
	in >> m.csec;
	normalize(m);
	return in;
}