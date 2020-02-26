#include <iostream>
#include <ctime>

using namespace std; 

void makeArr(int N, int*& p);
int* makeArr(int N);
void freeMemory(int*& A);
void printArray(int* beg, int* end);
void initRandomArray(int* beg, int* end, int m = -10, int M = 10);
void reverse(int* beg, int* end);
int* findFirstMin(int* beg, int* end);
int* findFirstMax(int* beg, int* end);
void bubbleSort(int* beg, int* end);
void quicksort(int* beg, int* end);
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

void freeMemory(int*& A)
{
	delete[] A;
	A = nullptr;
}

void printArray(int* beg, int* end)
{
	for (int* p = beg; p < end; ++p)
	{
		cout << *p << " ";
	}
	cout << '\n';
}

void initRandomArray(int* beg, int* end, int m, int M)
{
	srand(time(0));
	int d = M - m + 1;
	for (int* p = beg; p < end; ++p)
		*p = rand() % d + m;
}

int* findFirstMin(int* beg, int* end)
{
	int* min = beg;
	for (int* p = beg; p < end; ++p)
	{
		if (*p < *min)* min = *p;
	}
	return min;
}

int* findFirstMax(int* beg, int* end)
{
	int* max = beg;
	for (int* p = beg; p < end; ++p)
	{
		if (*p > * max)* max = *p;
	}
	return max;
}

void bubbleSort(int* beg, int* end)
{
	bool b = 1;
	while(b)
	{
		b = 0;
		for (int *j = beg; j < end - 1; ++j)
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
	int *b = beg; 
	int *e = end - 1;
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

void reverse(int* beg, int* end)
{
	int *p, *q;
	for (p = beg, q = end - 1; p < q; ++p, --q)
	{
		swap(*p, *q);
	}
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
