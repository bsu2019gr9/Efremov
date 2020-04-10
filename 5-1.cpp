#include <iostream>
using namespace std;

//Класс английские деньги(1 фунт стерлингов = 20 шиллингов ,1 шиллинг = 12 пенсов).
class EngMoney
{
private:
	int pound;
	int shill;
	int pence;

	friend void normalize(EngMoney& m);
public:
	EngMoney();
	EngMoney(int a, int b = 0, int c = 0);
	~EngMoney();
	EngMoney(const EngMoney& m);
    
	void operator=(const EngMoney& m);
	EngMoney operator+(const EngMoney& m) const;
	EngMoney operator-(const EngMoney& m) const;
	EngMoney operator*(const int n) const;
	EngMoney operator+=(const EngMoney& m);
	EngMoney operator-=(const EngMoney& m);
	EngMoney operator*=(const int n);
	bool operator==(const EngMoney& m) const;
	bool operator!=(const EngMoney& m) const;
	friend void operator<<(ostream& out, const EngMoney& m);
	friend void operator>>(istream& in, EngMoney& m);
};

EngMoney f1(EngMoney& m, EngMoney& n)
{
	if (m == n) { m *= 2; return m; }
	else { m -= n; return m;}
}
EngMoney f2(EngMoney* m)
{
	EngMoney n;
	for (int i = 0; i < 3; ++i)
		n += m[i];
	return n;
}

int main()
{
	EngMoney a(2, 19, 25);
	cout << a;
	EngMoney b;
	cin >> b;
	cout << b;
	cout << (a != b);
	EngMoney c[3] = { {3,20,45 }, 2, {4, 21} };
	for (int i = 0; i < 3; ++i)
		cout << c[i];
	EngMoney* d = c;
	cout << d[2];
	EngMoney* e = new (nothrow) EngMoney[4];
	e[0] = c[0];
	e[1] = a;
	e[2] = b;
	e[3] = { 2, 2, 8 };
	cout << a*3 - b + c[0];
	cout << f1(a, b);
	a = b;
	cout << f1(a, b);
	cout << f2(e);
	delete[] e;
}

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
	cout << "no params constructor working \n";
}
EngMoney::EngMoney(int a, int b, int c) :
	pound(a),
	shill(b),
	pence(c)
{
	normalize(*this);
	cout << "constructor working for " << this->pound << ' ' << this->shill << ' ' << this->pence << "\n";
}
EngMoney::~EngMoney()
{
	cout << "destructor working for...\n"; 
}
EngMoney::EngMoney(const EngMoney& m) :
	pound(m.pound),
	shill(m.shill),
	pence(m.pence)
{
	cout << "copy constructor working for" << this->pound << ' ' << this->shill << ' ' << this->pence << "\n";
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
	return EngMoney(pound += m.pound, shill += m.shill, pence += m.pence);
}
EngMoney EngMoney::operator-=(const EngMoney& m)
{
	return EngMoney(pound -= m.pound, shill -= m.shill, pence -= m.pence);
}
EngMoney EngMoney::operator*=(const int n)
{
	return(pound *= n, shill *= n, pence *= n);
}
bool EngMoney::operator==(const EngMoney& m) const
{
	return(pound == m.pound && shill == m.shill && pence == m.pence);
}
bool EngMoney::operator!=(const EngMoney& m) const
{
	return(pound != m.pound || shill != m.shill || pence != m.pence);
}
void operator<<(ostream& out, const EngMoney& m)
{
	out << m.pound << " po " << m.shill << " sh " << m.pence <<" pe"<< "\n";
}
void operator>>(istream& in, EngMoney& m)
{
	in >> m.pound;
	in >> m.shill;
	in >> m.pence;
	normalize(m);
}