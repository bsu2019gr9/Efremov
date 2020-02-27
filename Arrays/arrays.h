#pragma once
//одномерные массивы
void makeArr(int N, int*& p);
int* makeArr(int N);
void freeMemory(int*&);
void initRandomArray(int* beg, int* end, int m=-10, int M=10);
void printArray(int* beg, int* end);
void howManySomething(int* beg, int* end, const int);
void howManyMaxMin(int* beg, int*end);
int* findFirstMin(int* beg, int* end);
int* findFirstMax(int* beg, int* end);
void rightPermutation(int* beg, int* end);
void leftPermutation(int* beg, int* end);
void bubbleSort(int* beg, int* end);
void quicksort(int* beg, int* end);
void reverse(int* beg, int*end);
//двумерные массивы
int**& makeArrN(int N, int M);
int**& makeArrM(int M, int N);
void freeMemory(int**& p, int N);
void initRandomArrayM(int** p, int N, int M, int min = -10, int max = 10);
void initRandomArrayN(int** p, int N, int M, int min = -10, int max = 10);
void printArrayN(int** p, int N, int M);
void printArrayM(int** p, int N, int M);
