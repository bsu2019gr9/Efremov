#include "Swimmer.h"

Swimmer::Swimmer() :
	num(0),
	dist(0),
	name(new (nothrow) char[50]),
	time(0) 
{
	if (!name) { cout << "Error";  return; }
}

Swimmer::Swimmer(int n, int d, char* s_name, Time t) :
	num(n),
	dist(d),
	name(new (nothrow) char[strlen(s_name) + 1]),
	time(t)
{
	if (!name) { cout << "Error";  return; }
	strcpy(name, s_name);
}
Swimmer::~Swimmer()
{
	delete[] name;
}

Swimmer::Swimmer(const Swimmer& s) :
	num(s.num),
	dist(s.dist),
	name(new (nothrow) char[strlen(s.name) + 1]),
	time(s.time)
{
	if (!name) { cout << "Error";  return; }
	strcpy(name, s.name);
}

Swimmer::Swimmer(Swimmer&& s) :
	num(s.num),
	dist(s.dist),
	name(s.name),
	time(s.time)
{
	s.num = 0;
	s.dist = 0;
	s.name = nullptr;
	s.time = 0;
}

void Swimmer::setNum(const int n)
{
	if (n < 0) cout << "Wrong num";
	num = n;
}

void Swimmer::setDist(const int d)
{
	if (d < 0) cout << "Wrong dist";
	dist = d;
}

void Swimmer::setName(const char* s_name)
{
	if (!strlen(s_name)) cout << "Wrong name";
	delete[] name;
	name = new (nothrow) char[strlen(s_name) + 1];
	strcpy(name, s_name);
}

void Swimmer::setTime(const Time t)
{
	time = t;
}

Swimmer& Swimmer::operator=(const Swimmer& s)
{
	if (&s == this)
		return *this;
	num = s.num;
	dist = s.dist;
	time = s.time;

	if (name) delete[] name;
	name = new (nothrow) char[strlen(s.name) + 1];
	strcpy(name, s.name);

	return *this;
}

ostream& operator<<(ostream& out, const Swimmer& s)
{
	out << s.num << " | " << s.dist << "m | " << s.name << " | " << s.time;
	return out;
}

istream& operator>>(istream& in, Swimmer& s)
{
	cout << "\nnum: ";
	in >> s.num;
	cout << "dist: ";
	in >> s.dist;
	cout << "name: ";
	in >> s.name;
	cout << "time: ";
	in >> s.time;
	return in;
}

void Swimmer::remove()
{
	num = 0;
	dist = 0;
	delete[] name;
	name = nullptr;
	time = 0;
}

void makeSwimmer(Swimmer& s)
{
	cout << "Enter: number, distance, name, time";
	cin >> s;
}

void delSwimmer(Swimmer* list, int& N, int ind)
{
	if(!N) { cout << "Error";  return; }
	if (ind >= N) { cout << "bad index";  return; }
	swap(list[ind], list[N - 1]);
	list[N - 1].remove();	
	--N;
	cout << "swimmer #" << ind << " was deleted\n";
}

void editSwimmer(Swimmer& s)
{
	int nd;
	char s_name[50];
	Time t;
	int n;
	while (1)
	{
		cout << "Choose what do you want to eddit:\n1 -number, 2 -distance, 3 -name, 4 -time, 0 -exit.\n";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Enter number: ";
			cin >> nd;
			s.setNum(nd);
			break;
		case 2:
			cout << "Enter distance: ";
			cin >> nd;
			s.setDist(nd);
			break;
		case 3:
			cout << "Enter name: ";
			cin >> s_name;
			s.setName(s_name);
			break;
		case 4:
			cout << "Enter time: ";
			cin >> t;
			s.setTime(t);
			break;
		case 0:
			return;
		default:
			cout << "Error";
			break;
		}
	}
}

void printSwimmers(Swimmer* beg, Swimmer* end)
{
	Swimmer* tmp = beg;
	while (tmp != end)
	{
		cout << *tmp << "\n";
		++tmp;
	}
}

int readArrayOfSwimmers(Swimmer* s, const int N, char* filename)
{
	ifstream fin(filename, ios::binary);
	if (!fin) { cout << "File not found\n"; return 0; }
	int t = 0;
	char t_name[50];
	Time t_time = 0;
	int i = 0;
	while (i < N)
	{
		fin.read((char*)& t, sizeof(int));
		if (fin.eof()) break;
		s[i].setNum(t);
		fin.read((char*)& t, sizeof(int));
		s[i].setDist(t);
		fin.read((char*)& t_name, 50);
		s[i].setName(t_name);
		fin.read((char*)& t_time, sizeof(Time));
		s[i].setTime(t_time);
		++i;
	}
	fin.close();
	return i;
}

void writeArrayOfSwimmers(Swimmer* s, const int N, char* filename)
{
	if (!N) { cout << "Bad size"; return; }
	ofstream fout(filename, ios::binary);
	int t = 0;
	char t_name[50];
	Time t_time = 0;
	for (int i = 0; i < N; ++i)
	{
		t = s[i].getNum();
		fout.write((char*)& t, sizeof(int));
		t = s[i].getDist();
		fout.write((char*)& t, sizeof(int));
		strcpy(t_name, s[i].getName());
		fout.write((char*)& t_name, 50);
		t_time = s[i].getTime();
		fout.write((char*)& t_time, sizeof(Time));
	}
	fout.close();

}

void editSwimmersInFile()
{
	char filename[50];
	Swimmer* results = new (nothrow) Swimmer[200];
	int n = 0;
	int a = 1;
	cout << "Enter file name: ";
	cin >> filename;
	int size = readArrayOfSwimmers(results, 200, filename);
	printSwimmers(results, results + size);
	while (a)
	{
		cout << "Choose what do you want to do:\n1 -add swimmers, 2 -edit swimmers, 3 -delete swimmers, 0 -exit\n";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "How many swimmers do you want to add?\n";
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				makeSwimmer(results[i + size]);
			}
			size += n;
			printSwimmers(results, results + size);
			break;
		case 2:
			while (1)
			{
				cout << "What swimmers do you want to edit? (Write index then eddit. Enter -1 to quit)\n";
				cin >> n;
				if (n == -1) break;
				editSwimmer(results[n]);
				printSwimmers(results, results + size);
			}
			break;
		case 3:
			while (1)
			{
				cout << "What swimmers do you want to delete? (Write index. Enter -1 to quit)\n";
				cin >> n;
				if (n == -1) break;
				delSwimmer(results, size, n);
				printSwimmers(results, results + size);
			}
			break;
		case 0:
			a = 0;
			break;
		default:
			cout << "Error";
			break;
		}
	}
	writeArrayOfSwimmers(results, size, filename);
	delete[] results;
}

int findMaxNum(Swimmer* beg, Swimmer* end)
{
	Swimmer* max = beg;
	for (Swimmer* p = beg; p < end; ++p)
	{
		if ((*p).getNum() > (*max).getNum()) *max = *p;
	}
	return (*max).getNum();
}

void quickSortNum(Swimmer* beg, Swimmer* end)
{
	Swimmer a = *(beg + (end - beg) / 2);
	Swimmer* b = beg;
	Swimmer* e = end - 1;
	while (b <= e)
	{
		while ((*b).getNum() < a.getNum()) ++b;
		while ((*e).getNum() > a.getNum()) --e;
		if (b <= e)
		{
			swap(*b, *e);
			++b;
			--e;
		}
	}
	if (beg < e) quickSortNum(beg, e + 1);
	if (b < end) quickSortNum(b, end);
}
void quickSortTime(Swimmer* beg, Swimmer* end)
{
	Swimmer a = *(beg + (end - beg) / 2);
	Swimmer* b = beg;
	Swimmer* e = end - 1;
	while (b <= e)
	{
		while ((*b).getTime() < a.getTime()) ++b;
		while ((*e).getTime() > a.getTime()) --e;
		if (b <= e)
		{
			swap(*b, *e);
			++b;
			--e;
		}
	}
	if (beg < e) quickSortTime(beg, e + 1);
	if (b < end) quickSortTime(b, end);
}
void SortArrayOfSwimmersByNumAndTime(Swimmer *beg, Swimmer *end)
{
	Swimmer* p = beg;
	Swimmer* t = beg;
	quickSortNum(beg, end);
	while (p != end)
	{
		while ((*p).getNum() == (*t).getNum()) 
			++p;
		quickSortTime(t, p);
		t = p;
	}
}
Time countAverageTime(Swimmer* beg, Swimmer* end)
{
	Swimmer* p = beg;
	Time sum = 0;
	while (p != end)
	{
		sum += (*p).getTime();
		++p;
	}
	return (sum / (end - beg));
}
Swimmer* find3Winners(Swimmer* beg, Swimmer* end, Swimmer* win)
{
	Swimmer* b = beg;
	Swimmer* t = beg;
	int W = findMaxNum(beg, end) * 3;
	int j = 0;

	SortArrayOfSwimmersByNumAndTime(beg, end);
	if (win) delete[] win;
	win = nullptr;
	win = new (nothrow) Swimmer[W];
	Swimmer* w = win;

	while (b != end)
	{
		while ((*b).getNum() == (*t).getNum())
			++b;
		if (j <= W)
			for (int i = 0; i < 3; ++i)
			{
				*w = *t;
				++t;
				++w;
				++j;
			}
		t = b;
	}
	return win;
}