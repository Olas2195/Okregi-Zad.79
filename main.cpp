#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct wynik{
	string haslo;
  	int powtorzen;  	
};

class Zadanie77{
	ifstream we1, we2;
	ofstream wy;
	string napis1;
	string napis2;
	string klucz;  
	
	public:
		Zadanie77();
		~Zadanie77();
		void zadanie1();
		void zadanie2();
		void zadanie3();
		wynik szyfrowanie(string, string);
		string rozszyfrowanie(string, string);
};

Zadanie77::Zadanie77() {
	we1.open("dokad.txt");
	we2.open("szyfr.txt");
	wy.open("Vigenere_wyniki.txt");
	
	if(we1.good()) {
		getline(we1, napis1);
	}
	if(we2.good()) {
		getline(we2, napis2);
		getline(we2, klucz);
	}	
}

void Zadanie77::zadanie1() {
	cout<<"Zadanie 1: "<<"\n";
	wy<<"Zadanie 1: "<<"\n";
	wynik wynik1;
	wynik1 = this->szyfrowanie(napis1, "LUBIMYCZYTAC");
	cout<<wynik1.powtorzen<<" powtorzen\n";
	wy<<wynik1.powtorzen<<" powtorzen\n";
	cout<<wynik1.haslo<<"\n\n";
	wy<<wynik1.haslo<<"\n\n";		
}

void Zadanie77::zadanie2() {
	cout<<"Zadanie 2: "<<"\n";
	wy<<"Zadanie 2: "<<"\n";
	string wynik_z2 = this->rozszyfrowanie(napis2, klucz);
	cout<<wynik_z2<<"\n\n";	
	wy<<wynik_z2<<"\n\n";	
}

void Zadanie77::zadanie3() {
	double suma = 0.00;
	int n = 0;
	int t[26];
	
	cout<<"Zadanie 3: "<<"\n";
	wy<<"Zadanie 3: "<<"\n";
	
	for(int i=0; i<26; i++) {
		t[i] = 0;
	}
	for(int i=0; i<napis2.length(); i++) {
		t[int(napis2[i])-65]++;
	}
	for(int i=0; i<26; i++) {
		cout<<char(i+65)<<" - "<<t[i]<<" | ";
		wy<<char(i+65)<<" - "<<t[i]<<" | ";
	}
	cout<<"\n";
	wy<<"\n";
	
	for (int i=0; i<26; i++) {
		suma += t[i]*(t[i]-1);
		n += t[i];
	}
	double ko = suma/(n*(n-1));
	double d = 0.0285/(ko-0.0385);
	d *= 100;
	d = int(d);
	d /= 100;
	cout<<"Szacunkowa dlugosc klucza: "<<d<<"\n";
	wy<<"Szacunkowa dlugosc klucza: "<<d<<"\n";
	cout<<"Dokladna dlugosc klucza: "<<klucz.length();
	wy<<"Dokladna dlugosc klucza: "<<klucz.length();
}

wynik Zadanie77::szyfrowanie(string haslo, string szyfr) {
	int j = 0;
	for(int i=0; i<haslo.length(); i++) {
		if(haslo[i]!=' ' && haslo[i]!=',' && haslo[i]!='.') {
			int ilosc = int(szyfr[j%szyfr.length()])-65;
			haslo[i] = char((int(haslo[i])-65 + ilosc)%26+65);
			j++;
		}
	}
	int powtorzen = j/szyfr.length();
	if(j%szyfr.length()>0) {
		powtorzen++;
	}
	wynik wynik1;
	
	wynik1.haslo = haslo;
	wynik1.powtorzen = powtorzen;
	
	return wynik1;
}

string Zadanie77::rozszyfrowanie(string haslo, string szyfr) {
	int j = 0;
	for(int i=0; i<haslo.length(); i++) {
		if(haslo[i]!=' ' && haslo[i]!=',' && haslo[i]!='.') {
			int ilosc = int(szyfr[j%szyfr.length()])-65;
			ilosc = int(haslo[i])-65-ilosc;
			if(ilosc<0) {
				haslo[i] = char(26+ilosc+65);
			} else {
				haslo[i] = char(ilosc+65);
			}
			j++;
		}
	}
	return haslo;
}

Zadanie77::~Zadanie77() {
	we1.close();
	we2.close();
	wy.close();
}

int main() {
	Zadanie77 z77;
	z77.zadanie1();
	z77.zadanie2();
	z77.zadanie3();
	return 0;
}
