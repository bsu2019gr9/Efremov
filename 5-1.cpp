#include <iostream>
using namespace std;

//Класс английские деньги(1 фунт стерлингов = 20 шиллингов ,1 шиллинг = 12 пенсов).
class EngMoney
{
private:
	int pound;
	int shill;
	int pence;
public:
	EngMoney();
	EngMoney(int a, int b = 0, int c = 0);
	~EngMoney();
	EngMoney(const EngMoney& m);

	void operator=(const EngMoney& m);
	EngMoney operator+(const EngMoney& m);
	EngMoney operator-(const EngMoney& m);
	EngMoney operator*(const int n);
	friend void operator<<(ostream& out, const EngMoney& m);
	friend void operator>>(istream& in, EngMoney& m);
};

EngMoney f1(EngMoney& m)
{
	return m;
}
EngMoney* f2(EngMoney* m)
{
	return m;
}

int main()
{
	EngMoney a(2, 50, 13);
	cout << a;
	EngMoney b;
	cin >> b;
	cout << b;
	EngMoney c[3] = { {3,20,45 }, 2, {4, 21}};
	for (int i = 0; i < 3; ++i)
		cout << c[i];
	EngMoney* d = c;
	cout << *d;
	EngMoney* e = new (nothrow) EngMoney[4];
	*e = c[2];
	a = b;
	cout << a*3 - b + c[0];
	cout << f1(b);
	cout << f2(e)<<"\n";
	delete[] e;
}

EngMoney::EngMoney() :
	pound(0),
	shill(0),
	pence(0)
{
	cout << "no params constructor working \n";
}
EngMoney::EngMoney(int a, int b, int c) :
	pound(a + b / 20),
	shill(b % 20 + c / 12),
	pence(c % 12)
{
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
EngMoney EngMoney::operator+(const EngMoney& m)
{
	int po = pound + m.pound;
	int sh = shill + m.shill;
	int pe = pence + m.pence;
	return EngMoney(po + sh / 20, sh % 20 + pe / 12, pe % 12); //лишнее!!!!!!!!! Всё выполнит автоматически конструктор!!!!!
}
EngMoney EngMoney::operator-(const EngMoney& m)
{
	int po = pound - m.pound;
	int sh = shill - m.shill;
	int pe = pence - m.pence;
	return EngMoney(po - sh / 20, sh % 20 - pe / 12, pe % 12); //лишнее!!!!!!!!! Всё выполнит автоматически конструктор!!!!!
}
EngMoney EngMoney::operator*(const int n)
{
	int po = pound * n;
	int sh = shill * n;
	int pe = pence * n;
	return EngMoney(po + sh / 20, sh % 20 + pe / 12, pe % 12); //лишнее!!!!!!!!! Всё выполнит автоматически конструктор!!!!!
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
	m.shill = m.shill % 20 + m.pence / 12;
	
	m.pound += m.shill / 20;

	m.pence = m.pence % 12;
}
