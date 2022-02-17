#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

class Zadanie79{
	ifstream we;
	ofstream wy;
	double okregi[3][2000];
	
	public:
		Zadanie79();
		~Zadanie79();
		void zadania();
		void zadanie1();
		void zadanie2();
		void zadanie3();
};

Zadanie79::Zadanie79() {
	we.open("okregi.txt");
	wy.open("wyniki_okregi.txt");	
}

void Zadanie79::zadania() {
	int zad2 = 0;
	if(we.good()) {
		int i=0;
		while(!we.eof()) {
			we>>okregi[0][i];
			we>>okregi[1][i];
			we>>okregi[2][i];
			i++;
		}
		this->zadanie1();
		this->zadanie2();
		this->zadanie3();
    }
}

void Zadanie79::zadanie1() {
	int t[5] = {0, 0, 0, 0};
	for(int i=0; i<2000; i++) {
		double x = okregi[0][i];
		double y = okregi[1][i];
		double r = okregi[2][i];
		if(abs(x)>r && abs(y)>r) {
			if(x>0 && y>0) t[0]++;
			if(x<0 && y>0) t[1]++;
			if(x<0 && y<0) t[2]++;
			if(x>0 && y<0) t[3]++;
		} else t[4]++;
	}
	cout<<"Zadanie 1: \n Cwiartka 1: "<<t[0]<<"\n Cwiartka 2: "<<t[1]<<"\n Cwiartka 3: "<<t[2]<<"\n Cwiartka 4: "<<t[3]<<"\n Pozostale: "<<t[4]<<"\n";
	wy<<"Zadanie 1: \n Cwiartka 1: "<<t[0]<<"\n Cwiartka 2: "<<t[1]<<"\n Cwiartka 3: "<<t[2]<<"\n Cwiartka 4: "<<t[3]<<"\n Pozostale: "<<t[4]<<"\n";
}

void Zadanie79::zadanie2() {
	int ilosc = 0;
	for(int i=1; i<2000; i++) {
		double x1 = okregi[0][i];
		double y1 = okregi[1][i];
		double r1 = okregi[2][i];
		for(int j=0; j<i; j++) {
			double x2 = okregi[0][j];
			double y2 = okregi[1][j];
			double r2 = okregi[2][j];
			if(r1==r2) {
				if(x1==x2 && y1==-y2) ilosc++;
				if(x1==-x2 && y1==y2) ilosc++;
			}
		}
	}
	cout<<"\nZadanie 2:"<<ilosc<<"\n";
	wy<<"\nZadanie 2:"<<ilosc<<"\n";
}

void Zadanie79::zadanie3() {
	int ilosc = 0;
	for(int i=0; i<2000; i++) {
		double x1 = okregi[0][i];
		double y1 = okregi[1][i];
		double r1 = okregi[2][i];
		for(int j=i+1; j<2000; j++) {
			double x2 = okregi[0][j];
			double y2 = okregi[1][j];
			double r2 = okregi[2][j];
			if(r1==r2) {
				if(x1==-y2 && y1==x2) ilosc++;
				if(x2==-y1 && y2==x1) ilosc++;
			}
		}
	}
	cout<<"\nZadanie 3:"<<ilosc<<"\n";
	wy<<"\nZadanie 3:"<<ilosc<<"\n";
}

Zadanie79::~Zadanie79() {
	we.close();
	wy.close();
}

int main() {
	Zadanie79 z79;
	z79.zadania();
	return 0;
}
