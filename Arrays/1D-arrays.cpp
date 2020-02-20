//одномерные массивы
#include <iostream>
#include<ctime>

using namespace std;

void makeArr(int N, int*& p)
{
	p = new (nothrow) int[N];
	if (!p) exit(404);
}

void freeMemory(int*& A)
{
	delete[] A;
	A = nullptr;
}

void initRandomArray(int* beg, int* end, const int M, const int m)
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

int findMin(int* beg, int* end)
{
	int  min = *beg;
	for (int* p = beg; p < end; ++p)
	{
		if(*p < min) min = *p;
	}
	return min;
}

int findMax(int* beg, int* end)
{
	int  max = *beg;
	for (int* p = beg; p < end; ++p)
	{
		if(*p > max) max = *p;
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

//sortArr is coming soon

void reverse(int *beg, int *end)
{
	for (int *p=beg, int*q=end-1; p < q; ++p,--q)
	{
		swap(*p, *q);
	}
}
