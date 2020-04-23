#include <iostream>
#include <ctime>
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
	bool operator>(const EngMoney& m) const;
	bool operator>=(const EngMoney& m) const;
	bool operator<(const EngMoney& m) const;
	bool operator<=(const EngMoney& m) const;
	friend ostream& operator<<(ostream& out, const EngMoney& m);
	friend istream& operator>>(istream& in, EngMoney& m);
};

//--functions---------------------------------------------------------
void initRandomArray(EngMoney* beg, EngMoney* end, int m, int M)
{
	srand(time(0));
	int d = M - m + 1;
	for (EngMoney* p = beg; p < end; ++p)
		* p = { rand() % d + m, rand() % d + m, rand() % d + m };
}

void inputArray(EngMoney* beg, EngMoney* end)
{
	for (EngMoney* p = beg; p < end; ++p)
		cin >> *p;
};

void printArray(EngMoney* beg, EngMoney* end)
{
	for (EngMoney* p = beg; p < end; ++p)
		cout << *p << "\n";
}

EngMoney* findFirstMin(EngMoney* beg, EngMoney* end)
{
	EngMoney* min = beg;
	for (EngMoney* p = beg; p < end; ++p)
	{
		if (*p < *min)* min = *p;
	}
	return min;
}

EngMoney* findFirstMax(EngMoney* beg, EngMoney* end)
{
	EngMoney* max = beg;
	for (EngMoney* p = beg; p < end; ++p)
	{
		if (*p > * max)* max = *p;
	}
	return max;
}

void quickSort(EngMoney* beg, EngMoney* end)
{
	EngMoney a = *(beg + (end - beg) / 2);
	EngMoney* b = beg;
	EngMoney* e = end - 1;
	while (b <= e)
	{
		while (*b < a) ++b;
		while (*e > a) --e;
		if (b <= e)
		{
			swap(*b, *e);
			++b;
			--e;
		}
	}
	if (beg < e) quickSort(beg, e + 1);
	if (b < end) quickSort(b, end);
}

void howManySomething(EngMoney* beg, EngMoney* end, const EngMoney n)
{
	int s = 0;
	for (EngMoney* p = beg; p < end; ++p)
	{
		if (*p == n) ++s;
	}
	cout << "The number of " << n << " = " << s << '\n';
}

EngMoney countSum(EngMoney* beg, EngMoney* end)
{
	EngMoney sum = 0;
	for (EngMoney* p = beg; p < end; ++p)
		sum += *p;
	return sum;
}

EngMoney countSumOfElemsMoreThan(EngMoney* beg, EngMoney* end, EngMoney n)
{
	EngMoney sum = 0;
	for (EngMoney* p = beg; p < end; ++p)
		if (*p > n) sum += *p;
	return sum;
}

int main()
{
	const int N = 15;
	EngMoney* Arr = new (nothrow) EngMoney[N];
	initRandomArray(Arr, Arr + N, 0, 100);
	printArray(Arr, Arr + N);
	cout << countSum(Arr, Arr + N) << "\n";
	cout << countSumOfElemsMoreThan(Arr, Arr + N, {50, 5, 0}) << "\n";
	quickSort(Arr,Arr + N);
	printArray(Arr,Arr + N);
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
	out << m.pound << " po " << m.shill << " sh " << m.pence << " pe";
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
