#include <iostream>
#include "EngMoney.h"
using namespace std;

EngMoney* initArray(int N);
void inputArray(EngMoney* beg, EngMoney* end);
void printArray(EngMoney* beg, EngMoney* end);
EngMoney* findFirstMin(EngMoney* beg, EngMoney* end);
EngMoney* findFirstMax(EngMoney* beg, EngMoney* end);
void quickSort(EngMoney* beg, EngMoney* end);
void howManySomething(EngMoney* beg, EngMoney* end, const EngMoney n);
EngMoney countSum(EngMoney* beg, EngMoney* end);
EngMoney countSumOfElemsMoreThan(EngMoney* beg, EngMoney* end, EngMoney n);

int main()
{
	const int N = 2;
	EngMoney* Arr;
	Arr = initArray(N);
	inputArray(Arr, Arr + N);
	cout << countSum(Arr, Arr + N) << "\n";
	cout << countSumOfElemsMoreThan(Arr, Arr + N, {10, 10, 5}) << "\n";
	quickSort(Arr,Arr + N);
	printArray(Arr,Arr + N);
}

EngMoney* initArray(int N)
{
	EngMoney* p = new (nothrow) EngMoney[N];
	if (!p) exit(404);
	return p;
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