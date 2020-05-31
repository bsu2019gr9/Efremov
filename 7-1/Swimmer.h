#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iostream>
#include <fstream>
using namespace std;

//класс пловец: номер заплыва, дистанция, фамилия участника и его время
class Swimmer
{
private:
	int num;//для одинаковых номеров дистанция одинаковая иначе нет возможности сравнивать результаты
	int dist;//m
	char* name;
	Time time;

public:
	Swimmer();
	Swimmer(int n, int d, char* s_name, Time t);
	~Swimmer();
	Swimmer(const Swimmer& s);
	Swimmer(Swimmer&& s);

	int getNum() const { return num; }
	int getDist() const { return dist; }
	char* getName() const { return name; }
	Time getTime() const { return time; }
	void setNum(const int n);
	void setDist(const int d);
	void setName(const char* s_name);
	void setTime(const Time t);

	Swimmer& operator=(const Swimmer& s);;
	friend ostream& operator<<(ostream& out, const Swimmer& s);
	friend istream& operator>>(istream& in, Swimmer& s);
	void remove();

};

void makeSwimmer(Swimmer& s);
void delSwimmer(Swimmer* list, int& N, int ind);
void editSwimmer(Swimmer& s);
void printSwimmers(Swimmer* beg, Swimmer* end);

int readArrayOfSwimmers(Swimmer* s, const int N, char* filename);
void writeArrayOfSwimmers(Swimmer* s, const int N, char* filename);
void editSwimmersInFile();

int findMaxNum(Swimmer* beg, Swimmer* end);
void quickSortNum(Swimmer* beg, Swimmer* end);
void quickSortTime(Swimmer* beg, Swimmer* end);
void SortArrayOfSwimmersByNumAndTime(Swimmer* beg, Swimmer* end);

Time countAverageTime(Swimmer* beg, Swimmer* end);
Swimmer* find3Winners(Swimmer* beg, Swimmer* end, Swimmer* win);