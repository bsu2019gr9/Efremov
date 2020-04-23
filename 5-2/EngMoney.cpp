#include <iostream>
#include "EngMoney.h"
using namespace std;

//Класс английские деньги(1 фунт стерлингов = 20 шиллингов ,1 шиллинг = 12 пенсов).
void normalize(EngMoney& m)
{
	m.pound += m.shill / 20 + m.pence / 240;
	m.shill = m.shill % 20 + (m.pence / 12) % 20;
	m.pence %= 12;
	if (m.shill >= 20 || m.shill <= 20)
	{
		m.pound += m.shill / 20;
		m.shill %= 20;
	}
}

EngMoney::EngMoney() :
	pound(0),
	shill(0),
	pence(0)
{
	//cout << "no params constructor working \n";
}

EngMoney::EngMoney(int a, int b, int c) :
	pound(a),
	shill(b),
	pence(c)
{
	normalize(*this);
	//cout << "constructor working for " << this->pound << ' ' << this->shill << ' ' << this->pence << "\n";
}

EngMoney::~EngMoney()
{
	//cout << "destructor working for...\n"; 
}

EngMoney::EngMoney(const EngMoney& m) :
	pound(m.pound),
	shill(m.shill),
	pence(m.pence)
{
	//cout << "copy constructor working for" << this->pound << ' ' << this->shill << ' ' << this->pence << "\n";
}

void EngMoney::operator=(const EngMoney& m)
{
	pound = m.pound;
	shill = m.shill;
	pence = m.pence;
}

EngMoney EngMoney::operator+(const EngMoney& m) const
{
	return EngMoney(pound + m.pound, shill + m.shill, pence + m.pence);
}

EngMoney EngMoney::operator-(const EngMoney& m) const
{
	return EngMoney(pound - m.pound, shill - m.shill, pence - m.pence);
}

EngMoney EngMoney::operator*(const int n) const
{
	return EngMoney(pound * n, shill * n, pence * n);
}

EngMoney EngMoney::operator+=(const EngMoney& m)
{
	pound += m.pound;
	shill += m.shill;
	pence += m.pence;
	normalize(*this);
	return EngMoney(*this);
}

EngMoney EngMoney::operator-=(const EngMoney& m)
{
	pound -= m.pound;
	shill -= m.shill;
	pence -= m.pence;
	normalize(*this);
	return EngMoney(*this);
}

EngMoney EngMoney::operator*=(const int n)
{
	pound *= n;
	shill *= n;
	pence *= n;
	normalize(*this);
	return EngMoney(*this);
}

bool EngMoney::operator==(const EngMoney& m) const
{
	return(pound == m.pound && shill == m.shill && pence == m.pence);
}

bool EngMoney::operator!=(const EngMoney& m) const
{
	return(pound != m.pound || shill != m.shill || pence != m.pence);
}

bool EngMoney::operator>(const EngMoney& m) const
{
	return(pound * 240 + shill * 12 + pence > m.pound * 240 + m.shill * 12 + m.pence);
}

bool EngMoney::operator>=(const EngMoney& m) const
{
	return(pound * 240 + shill * 12 + pence >= m.pound * 240 + m.shill * 12 + m.pence);
}

bool EngMoney::operator<(const EngMoney& m) const
{
	return(pound * 240 + shill * 12 + pence < m.pound * 240 + m.shill * 12 + m.pence);
}

bool EngMoney::operator<=(const EngMoney& m) const
{
	return(pound * 240 + shill * 12 + pence <= m.pound * 240 + m.shill * 12 + m.pence);
}

ostream& operator<<(ostream& out, const EngMoney& m)
{
	out << m.pound << " po " << m.shill << " sh " << m.pence <<" pe";
	return out;
}

istream& operator>>(istream& in, EngMoney& m)
{
	in >> m.pound;
	in >> m.shill;
	in >> m.pence;
	normalize(m);
	return in;
}