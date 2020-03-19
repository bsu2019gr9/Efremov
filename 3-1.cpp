//Особая пара - слова стоящие рядом и заданная буква встречается в них одинаковое количество раз
//на одинаковых позициях. Вывести все особые пары и удалить их
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void task3(char*& str, char symbol, char* sep);
int isSpecialPairs(char *p1, char *p2, char symbol);
void delStr(char*& str, char *b, int kol);

int main()
{
	int size = 100000;
	char symbol = 0;
	char sep[] = " .,?!'`-:;";
	char* str = new (nothrow) char[size];
	cout << "Enter text\n";
	cin.getline(str, size);
	cout << "Enter symbol:\n";
	cin >> symbol;
	cout << "Spesial pairs:\n";
	task3(str, symbol, sep);
	cout << str;
}

void task3(char *&str, char symbol, char *sep)
{
	char* tmp_str = new (nothrow) char[strlen(str)+1];
	strcpy(tmp_str, str);
	char *p1 = strtok(tmp_str,sep);
	char *p2 = strtok(nullptr, sep);
	char* q = nullptr;
	int len = 0;
	while (p2)
	{
		if (isSpecialPairs(p1, p2, symbol))
		{
			cout << p1 << " " << p2 << '\n';
			q = strstr(str, p1);
			delStr(str, q, strlen(p1));  
			q = strstr(str, p2);
			delStr(str, q, strlen(p2));  
			p1 = strtok(nullptr, sep);
			p2 = strtok(nullptr, sep);
		}
		else
		{
			swap(p1, p2);
			p2 = strtok(nullptr, sep);
		}

	}
}

int isSpecialPairs(char* p1, char* p2, char symbol)
{
	int c = 0, q = 0;
	if (strlen(p1) < strlen(p2)) swap(p1, p2);
	for (int i = 0; i < strlen(p1); ++i)
		if (p1[i] == symbol) ++q;
	for (int i = 0; i < strlen(p2); ++i)
		if (p1[i] == symbol && p1[i] == p2[i]) ++c;
	if (c == q && c) return 1;
	else return 0;
}

void delStr(char*& str, char *b, int kol)
{
	char* tmp_str = new (nothrow) char[strlen(str) - kol+1];
	int i = 0;
	while (str++!=b) ++i;
	str -= (i+1);
	strncpy(tmp_str, str, i);
	strcpy(tmp_str + i, str + i + kol);
	delete[] str;
	str = tmp_str;
}

char* findStr(char* str, char *p, int dif)
{
	char* t = 0;
	int j = 0;
	while (str)
	{
		t = strstr(str, p);
		j = str - t;
		if (j == dif) return t; 
	}
	return nullptr;
}