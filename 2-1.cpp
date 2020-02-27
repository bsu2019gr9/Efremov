//В массиве А(N,M) расположить столбцы по возрастанию количества чётных элементов в столбце
#include <iostream>
#include <ctime>
#include <iomanip>
#include "arrays.h"

using namespace std;

int**& makeArrM(int M, int N);
void initRandomArrayM(int** p, int N, int M, int min = -10, int max = 10);
void printArrayM(int** p, int N, int M);

int howManyEvenElementsInCol(int** p, int N, int M);
void bubbleSortOfColsWithEvenElements(int**& p, int N, int M);

int main()
{
	int N, M;
	cout << "Enter size of array (rows, cols)\n";
	cin >> N >> M;
	int** p = makeArrM(N, M);
	initRandomArrayM(p, N, M);
	printArrayM(p, N, M);
	bubbleSortOfColsWithEvenElements(p, N, M);
	printArrayM(p, N, M);
	freeMemory(p, M);
}

int howManyEvenElementsInCol(int** p, int N, int i)
{
	int k = 0;
	for (int j = 0; j < N; ++j)
		if (!(p[i][j] % 2) && p[i][j]) ++k;
	return k;
}

void bubbleSortOfColsWithEvenElements(int**& p, int N, int M)
{
	bool b = 1;
	while (b)
	{
		b = 0;
		for (int i = 0; i < M - 1; ++i)
			if (howManyEvenElementsInCol(p,N,i) > howManyEvenElementsInCol(p, N, i+1))
			{
				swap(p[i], p[i + 1]);
				b = 1;
			}
		--M;
	}
}
