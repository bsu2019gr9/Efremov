//одномерные массивы
#include <iostream>
using namespace std;

int* giveMemory(int N)
{
	int* A;
	try {
		A = new int[N];
		A = { 0 };
		return A;
	}
	catch (...) {
		cout << "error";
	}
}

void freeMemory(int A[]) 
{
	delete[] A;
}

void initRandomArray(int A[], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		int k = rand() % 10 - 1;
		A[i] = k;
	}
}

void printArray(int A[], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		cout << A[i] << " ";
	}
	cout << '\n';
}

void howManySomething(int A[], const int n, const int N)
{
	int s = 0;
	for (int i = 0; i < N; ++i)
	{
		if(A[i] == n) ++s;
	}
	cout << "The number of " << n << " = " << s <<'\n';
}

void howManyMaxMin(int A[], const int N)
{
	int nmin = 0, nmax = 0, max = A[0], min = A[0];
	for (int i = 0; i < N; ++i)
	{
		if (A[i] > max)
		{
			max = A[i];
			nmax = 0;
		}
		if (A[i] < min)
		{
			min = A[i];
			nmin = 0;
		}
		if (A[i] == max)
			++nmax;
		if (A[i] == min)
			++nmin;
	}
	cout << "max = " << max << '\n' << "min = " << min << '\n' << "Number of max = " << nmax << '\n' << "Number of min = " << nmin << '\n';
}

int findMin(int A[], const int N)
{
	int  min = A[0];
	for (int i = 0; i < N; ++i)
	{
		if(A[i] < min) min = A[i];
	}
	return min;
}

int findMax(int A[], const int N)
{
	int  max = A[0];
	for (int i = 0; i < N; ++i)
	{
		if(A[i] > max) max = A[i];
	}
	return max;
}

void rightPermutation(int A[], const int N)
{
	int t;
	for (int i = 1; i < N; ++i)
	{
		t = A[N - i];
		A[N - i] = A[N - i - 1];
		A[N - i - 1] = t;
	}
}

void leftPermutation(int A[], const int N)
{
	int t;
	for (int i = 0; i < N - 1; ++i)
	{
		t = A[i];
		A[i] = A[i + 1];
		A[i + 1] = t;
	}
}

void sortArr(int A[],const int N)
{
	int i = 0, j = 1;
	int *B=new int[N];
	for (int m = 0; m < N; ++m)
	{
		if (A[m] > 0) { B[i] = A[m]; ++i; }
		if (A[m] < 0) { B[N - j] = A[m]; ++j; }
	}
	for (int q = 0; q < N; ++q)
		A[q] = B[q];
}

void reverse(int A[], const int N)
{
	int* B = new int[N];
	for (int i = 0; i < N; ++i)
		B[N - i - 1] = A[i];
	for (int i = 0; i < N; ++i)
		A[i] = B[i];
}
