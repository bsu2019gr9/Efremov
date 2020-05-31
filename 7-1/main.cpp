/*Определить класс, предусмотрев в нём
* приватные (защищенные) поля
* конструкторы (по умолчанию, и еще несколько – с параметрами), конструктор копирования,
* деструктор 
* конструктор перемещения и копирующее присваивание 
* функции ввода, вывода членов класса 
* если надо, то функции для доступа к защищенным членам класса (геттеры)
* свои функции, которые вам необходимы для работы с объектами данного класса исходя из условия задачи.
* Запись/чтение из файла массива объектов.
* Изменение единичного объекта в файле
* Измененеие группы объектов в файле
Написать программу, которая с помощью меню демонстрирует использование созданного класса и осуществляет
проверку всех функций класса*/

/*В объекте хранятся результаты соревнований по плаванию: номер заплыва, дистанция, фамилия участника и его время.
a) Создания/удаления/редактирования участника и его результата
b) Вывести список участников каждого заплыва, упорядоченный в порядке убывания результатов заплыва.
c) Вычислить среднее время во всех заплывах и в каждом заплыве определить трёх победителей.*/

#define _CRT_SECURE_NO_WARNINGS
#include "Swimmer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int action = 1;
	int num = 0;
	int N = 0;
	char* filename = new (nothrow) char[50];
	Swimmer* results = new (nothrow) Swimmer[200];
	Swimmer* winners = new (nothrow) Swimmer[3];
	int W;
	while (action)
	{
		cout << "Choose what do you want to do:\n";
		cout << "1 -make new results of swimming contest\n";
		cout << "2 -read results of swimming contest from file\n";
		cout << "3 -write results of swimming contest in file\n";
		cout << "4 -eddit results of swimming contest in file\n";
		cout << "5 -print results\n";
		cout << "6 -sort results by number and time of swim\n";
		cout << "7 -count average time in all swims\n";
		cout << "8 -find 3 winners in every swim\n";
		cout << "0 -quit\n";
		cin >> action;
		switch (action)
		{
		case 1:
			cout << "Enter number of participants: ";
			cin >> N;
			if (N <= 0) { cout << "Bad number"; break; }
			delete[] results;
			results = new (nothrow) Swimmer[N];
			for (int i = 0; i < N; ++i)
			{
				makeSwimmer(results[i]);
			}
			break;
		case 2:
			cout << "Enter file name: ";
			cin >> filename;
			delete[] results;
			results = nullptr;
			results = new (nothrow) Swimmer[200];
			N = readArrayOfSwimmers(results, 200, filename);
			break;
		case 3:
			if (!N) { cout << "Results wasnt created\n"; break; }
			cout << "Enter file name: ";
			cin >> filename;
			writeArrayOfSwimmers(results, N, filename);
			break;
		case 4:
			editSwimmersInFile();
			break;
		case 5:
			if (!N) { cout << "Results wasnt created\n"; break; }
			printSwimmers(results, results + N);
			break;
		case 6:
			if (!N) { cout << "Results wasnt created\n"; break; }
			SortArrayOfSwimmersByNumAndTime(results, results + N);
			break;
		case 7:
			if (!N) { cout << "Results wasnt created\n"; break; }
			cout << countAverageTime(results, results + N) << "\n";
			break;
		case 8:
			if (!N) { cout << "Results wasnt created\n"; break; }
			if (N < 3) { cout << "Not enough participants\n"; break; }
			winners = find3Winners(results, results + N, winners);
			W = findMaxNum(results, results + N) * 3;
			printSwimmers(winners, winners + W);
			break;
		case 0:
			break;
		default:
			cout << "wrong operation\ntry again\n";
			break;
		}
	}
	delete[] results;
	delete[] filename;
	delete[] winners;
}