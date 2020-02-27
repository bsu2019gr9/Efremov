#include <iostream>
#include <ctime>
#include "arrays.h"

using namespace std; 

int task1(int* beg, int* end);//подсчитать количество элементов, встречающихся более одного раза
int task2(int* beg, int* end);//определить максимальную длину последовательности равных элементов

int main()
{
	int S;
	int* Arr;
	cout << "Enter size of array" << '\n';
	cin >> S;
	Arr = makeArr(S);
	initRandomArray(Arr, Arr + S);
	printArray(Arr,Arr+S);
	cout << "Task1: " << task1(Arr, Arr + S) << '\n';
	initRandomArray(Arr, Arr + S, -10, 20);
	cout << "Task2: " << task2(Arr, Arr + S) << '\n';
	freeMemory(Arr);
}

//подсчитать количество элементов, встречающихся более одного раза
int task1(int* beg, int* end)
{
	quicksort(beg, end);
	int N = 0, k = 0;
	for (int* i = beg; i < end; ++i)
	{
		while (*i == *(i + 1) && i < end)
		{
			++k;
			++i;
		}
		if (k) ++N;
		k = 0;
	}
	return N;
}

//определить максимальную длину последовательности равных элементов
int task2(int* beg, int* end)
{
	int length = 1, k = 1;
	for (int *i = beg; i < end; ++i)
	{
		while (*i == *(i + 1) && i < end)
		{
			++k;
			++i;
		}
		if (length < k) length = k;
		k = 1;
	}
	return length;
}
