#include<iostream>
#include<fstream>  
using namespace std;
struct color
{ 
	unsigned char b;
	unsigned char g; 
	unsigned char r;
};

int main() {
	ifstream fin("d:\\1.bmp", ios::binary); 
	ofstream fout("d:\\rez.bmp", ios::binary);
	if (!fin) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!fout) { cout << "Can't create file d:\\rez.bmp.\n"; exit(1); }

	char buf[30];
	color c1, c2;
	unsigned int w, h;

	fin.read((char*)& buf, 18);   
	fout.write((char*)& buf, 18);   
	fin.read((char*)& buf, 4);
	fin.read((char*)& buf, 4);
	w = 400;
	fout.write((char*)& w, 4);
	h = 600;
	fout.write((char*)& h, 4);    
	fin.read((char*)& buf, 28);   
	fout.write((char*)& buf, 28);   

	c1.r = 220; c1.g = 200; c1.b = 100;
	c2.r = 20; c2.g = 100; c2.b = 250; 

	double stepR = (c2.r - c1.r) * 1.0 / w;
	double stepG = (c2.g - c1.g) * 1.0 / w;
	double stepB = (c2.b - c1.b) * 1.0 / w;
	double R = c1.r, G = c1.g, B = c1.b;
	double tR = R, tG = G, tB = B;
	
	cout << "Enter: 1 -vertical gradient, 2 -horizontal gradient\n";
	int action = 0;
	cin >> action;

	switch (action)
	{
	case 1:
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < h; ++j)
				fout.write((char*)& c1, 3);

			tR += stepR;
			tG += stepG;
			tB += stepB;
			c1.r = tR;
			c1.g = tG;
			c1.b = tB;
		}
		break;
	case 2:
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				tR += stepR;
				tG += stepG;
				tB += stepB;
				c1.r = tR;
				c1.g = tG;
				c1.b = tB;
				fout.write((char*)& c1, 3);
			}
			tR = R;
			tG = G;
			tB = B;
		}
		break;
	default:
		cout << "Error";
		break;
	}

	fin.close();
	fout.close();
}