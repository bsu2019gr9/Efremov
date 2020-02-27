//одномерные массивы
#include <iostream>
#include <ctime>
#include <iomanip>
#include "arrays.h"

using namespace std;

void makeArr(int N, int*& p)
{
	p = new (nothrow) int[N];
	if (!p) exit(404);
}

int* makeArr(int N)
{
	int* p = new(nothrow) int[N];
	if (!p) exit(404);
	return p;
}

void freeMemory(int*& p)
{
	delete[] p;
	p = nullptr;
}

void initRandomArray(int* beg, int* end, int m, int M)
{
	srand(time(0));
	int d = M - m + 1;
	for (int* p = beg; p < end; ++p)
		 *p = rand() % d + m;
}

void printArray(int *beg, int *end)
{
	for (int *p = beg; p < end; ++p)
	{
		cout << *p << " ";
	}
	cout << '\n';
}

void howManySomething(int* beg, int* end , const int n)
{
	int s = 0;
	for (int* p = beg; p < end; ++p)
	{
		if( *p == n) ++s;
	}
	cout << "The number of " << n << " = " << s <<'\n';
}

void howManyMaxMin(int* beg, int* end)
{
	int nmin = 0, nmax = 0, max = *beg, min = *beg;
	for (int* p = beg; p < end; ++p)
	{
		if (*p > max)
		{
			max = *p;
			nmax = 0;
		}
		if (*p < min)
		{
			min = *p;
			nmin = 0;
		}
		if (*p == max)
			++nmax;
		if (*p == min)
			++nmin;
	}
	cout << "max = " << max << '\n' << "min = " << min << '\n' << "Number of max = " << nmax << '\n' << "Number of min = " << nmin << '\n';
}

int* findFirstMin(int* beg, int* end)
{
	int  *min = beg;
	for (int* p = beg; p < end; ++p)
	{
		if(*p < *min) *min = *p;
	}
	return min;
}

int* findFirstMax(int* beg, int* end)
{
	int *max = beg;
	for (int* p = beg; p < end; ++p)
	{
		if(*p > *max) *max = *p;
	}
	return max;
}

void leftPermutation(int* beg, int* end)
{
	for (int* p = beg; p < end - 1; ++p)
	{
		swap(*p, *(p + 1));
	}
}

void rightPermutation(int* beg, int* end)
{
	for (int* p = end - 1; p > beg; --p)
	{
		swap(*p, *(p - 1));
	}
}

void bubbleSort(int* beg, int* end)
{
	bool b = 1;
	while (b)
	{
		b = 0;
		for (int* j = beg; j < end - 1; ++j)
			if (*j > * (j + 1))
			{
				swap(*j, *(j + 1));
				b = 1;
			}
		--end;
	}
}

void quicksort(int* beg, int* end)
{
	int a = *(beg + (end - beg) / 2);
	int* b = beg;
	int* e = end - 1;
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
	if (beg < e) quicksort(beg, e + 1);
	if (b < end) quicksort(b, end);
}

void reverse(int *beg, int *end)
{
	int* p, * q;
	for (p=beg, q=end-1; p < q; ++p,--q)
	{
		swap(*p, *q);
	}
}

//двумерные массивы
int**& makeArrN(int N, int M)
{
	int** p = new (nothrow) int* [N];
	for (size_t i = 0; i < N; ++i)
		p[i] = nullptr;
	for (size_t i = 0; i < N; ++i)
		p[i] = new (nothrow) int[M];
	if (!p) exit(404);
	return p;
}

int**& makeArrM(int N, int M)
{
	int** p = new (nothrow) int* [M];
	for (int i = 0; i < M; ++i)
		p[i] = nullptr;
	for (int i = 0; i < M; ++i)
		p[i] = new (nothrow) int[N];
	if (!p) exit(404);
	return p;
}

void freeMemory(int**& p, int N)
{
	for (size_t i = 0; i < N; ++i) delete p[i];
	delete[] p;
	p = nullptr;
}

void initRandomArrayN(int** p, int N, int M, int min, int max)
{
	srand(time(0));
	int d = max - min + 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			p[i][j] = rand() % d + min;
}

void initRandomArrayM(int** p, int N, int M, int min, int max)
{
	srand(time(0));
	int d = max - min + 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			p[j][i] = rand() % d + min;
}

void printArrayN(int** p, int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout <<setw(4)<< p[i][j];
		}
		cout << '\n';
	}
	cout << "------------------------------\n";
}

void printArrayM(int** p, int N, int M)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << setw(4) << p[j][i];
		}
		cout << '\n';
	}
	cout << "------------------------------\n";
}