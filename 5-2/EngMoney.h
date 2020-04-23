#pragma once
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
	bool operator>(const EngMoney& m) const;
	bool operator>=(const EngMoney& m) const;
	bool operator<(const EngMoney& m) const;
	bool operator<=(const EngMoney& m) const;
	friend ostream& operator<<(ostream& out, const EngMoney& m);
	friend istream& operator>>(istream& in, EngMoney& m);
};