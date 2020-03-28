//В тексте выбрать все слова, начинающиеся с заданной буквы, и расположить их в порядке убывания количества букв в слове.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream> 
using namespace std;

void findWordsStartingWith(char**& all_words, char* buff, char sym, char* sep, int*& all_lengths);
void freeMemory(char**& p, int N);
void insertionSort(int* beg_l, int* end_l, char** beg_w);

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Ru");
	const int N = 100000;
	const int L = 1000000;
	char* buff = new (nothrow) char[N];
	char** all_words = new (nothrow) char* [L];
	int* all_lengths = new (nothrow) int[L];
	char sep[] = "` ., '\":;!?\t()";
	char sym;

	cout << "use Windows-1251 encoding!\n";
	ifstream Fin("d:\\2.txt");
	ofstream Fout("d:\\result.txt");
	if (!Fin) { cout << "Can't open file\n"; exit(1); }
	if (!Fout) { cout << "Can't create file\n"; exit(1); }
	cout << "Enter symbol\n";
	cin >> sym;

	int* beg_l = all_lengths;
	char** beg_w = all_words;
	while (1)
	{
		Fin.getline(buff, N - 1);
		if (Fin.fail()) Fin.clear();
		findWordsStartingWith(all_words, buff, sym, sep, all_lengths);
		if (Fin.eof()) break;
	}

	delete[] buff;
	*all_lengths = 0;
	*all_words = 0;
	insertionSort(beg_l, all_lengths, beg_w);

	int i = 0;
	while (beg_w[i]) Fout << beg_w[i++] <<"\n";

	Fin.close();
	Fout.close();
	freeMemory(beg_w, L);
	delete[] beg_l;
}

void findWordsStartingWith(char**& all_words, char* buff, char sym, char* sep, int*& all_lengths)
{
	char* p = strtok(buff, sep);
	while (p)
	{
		if (*p == sym)
		{
			*all_lengths++ = strlen(p);
			*all_words = new char[strlen(p)+1];
			strcpy(*all_words, p);
			++all_words;
		}
		p = strtok(nullptr, sep);
	}
}

void insertionSort(int* beg_l, int* end_l, char** beg_w)
{
	char** q = beg_w + 1;
	for (int* i = beg_l + 1; i < end_l; ++i,++q) 
	{
		int* j = i;
		char** p = q;
		while (j > beg_l && *(j - 1) < * j) 
		{
			swap(*(j - 1), *j);
			swap(*(p - 1), *p);
			--j;
			--p;
		}
	}
}

void freeMemory(char**& p, int N)
{
	char** q = p;
	for (int i = 0; i < N; ++i)
	{
		if (*q) delete* q++;
	}
	delete[] p;
	p = nullptr;
}
