#include <iostream>
#include <fstream>

using namespace std;

class Zadanie76{
	ifstream we1, we2, we3;
	ofstream wy;
	
	public:
		Zadanie76();
		~Zadanie76();
		void zadanie1();
		void zadanie2();
		void zadanie3();
		void sort(string napis, int P[], int size);
		void desort(string napis, int P[], int size);
};

Zadanie76::Zadanie76() {
	we1.open("szyfr1.txt");
	we2.open("szyfr2.txt");
	we3.open("szyfr3.txt");
	wy.open("wyniki_szyfr.txt");
}

void Zadanie76::zadanie1() {
	string napisy[6];
	int P[50];
	if(we1.good()) {
		while(!we1.eof()) {
			for(int i=0; i<6; i++) {
				we1>>napisy[i];
			}
			for(int i=0; i<50; i++) {
				we1>>P[i];
			}
		}
		cout<<"Zadanie 1: "<<"\n";
		wy<<"Zadanie 1: "<<"\n";
		for(int i=0; i<6; i++) {
			this->sort(napisy[i], P, sizeof(P)/sizeof(int));
			cout<<"\n";
			wy<<"\n";
		}
		cout<<"\n";
		wy<<"\n";
    }
}

void Zadanie76::zadanie2() {
	string napis;
	int P[15];
	if(we2.good()) {
		while(!we2.eof()) {
			we2>>napis;
			for(int i=0; i<15; i++) {
				we2>>P[i];
			}
		}
		cout<<"Zadanie 2: "<<"\n";
		wy<<"Zadanie 2: "<<"\n";
		this->sort(napis, P, sizeof(P)/sizeof(int));
		cout<<"\n\n";
		wy<<"\n\n";
    }
}

void Zadanie76::zadanie3() {
	string napis;
	int A[] = {6, 2, 4, 1, 5, 3};
	if(we3.good()) {
		while(!we3.eof()) {
			we3>>napis;
		}
		cout<<"Zadanie 3: "<<"\n";
		wy<<"Zadanie 3: "<<"\n";
		this->desort(napis, A, sizeof(A)/sizeof(int));
		cout<<"\n\n";
		wy<<"\n\n";
    }
}

void Zadanie76::sort(string napis, int P[], int size) {
	char buffor;
	for(int i=0; i<napis.length(); i++) {
		buffor = napis[P[i%size]-1];
		napis[P[i%size]-1] = napis[i];
		napis[i] = buffor;
	}
	cout<<napis;
	wy<<napis;
}

void Zadanie76::desort(string napis, int P[], int size) {
	char buffor;
	for(int i=napis.length()-1; i>=0; i--) {
		buffor = napis[P[i%size]-1];
		napis[P[i%size]-1] = napis[i];
		napis[i] = buffor;
	}
	cout<<napis;
	wy<<napis;
}

Zadanie76::~Zadanie76() {
	we1.close();
	we2.close();
	we3.close();
	wy.close();
}

int main() {
	Zadanie76 z76;
	z76.zadanie1();
	z76.zadanie2();
	z76.zadanie3();
	return 0;
}
