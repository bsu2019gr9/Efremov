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
int**& makeArr(int N, int M);
void freeMemory(int**& p, int N);
void initRandomArray(int** p, int N, int M, int min, int max);
void printArray(int** p, int N, int M);