#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class palindrom {
	ifstream plik1;
	ofstream plik2;
	string napis;
	
	public:
		palindrom();
		~palindrom();
		
		void wczytywanie();		
		void isPalindrom(string napis);
		void wpisanieDoPliku(bool palindrome, string napis);
};

palindrom::palindrom() {
	plik1.open("we.txt");
	plik2.open("wy.txt");
}

void palindrom::wczytywanie() {
	plik2<<"[\n";
	cout<<"[\n";
	if(plik1.good())
		while(!plik1.eof()) {
			getline(plik1, napis);
			this->isPalindrom(napis);
		}
	plik2<<"]";
	cout<<"]";
}

void palindrom::isPalindrom(string napis) {
	stringstream s(napis);
	string slowo;
	string polacz("");

	while(s>>slowo) {		//usuwanie spacji
		polacz += slowo;
	}
	napis = polacz;
	
	for(int i=0; i<napis.length(); i++) {	//zmienianie na małe litery
		if(napis[i]>64 && napis[i]<90)
			napis[i]+=32;
	}
		
	int back = napis.length()-1;	//ostatnia litera napisu
	bool palindrome = true;			//zakładamy, że napis jest palindromem
	for(int i=0; i<napis.length()/2 && palindrome; i++) { 	//tylko do połowy stringu
		if(napis[i]!=napis[back--])		//back po przedstawieniu zmniejszy się o 1 z ostatniej na przedostatniš itd.
			palindrome = false;
	}
	
	this->wpisanieDoPliku(palindrome, napis);
} 

void palindrom::wpisanieDoPliku(bool palindrome, string napis) {
	string wartosc;
	if(palindrome==true)
		wartosc = "TAK";
	else
		wartosc = "NIE";
				
	cout<<"{\"string\": \""<<napis<<"\", \"palindrom\": \""<<wartosc<<"\"};\n";
	plik2<<"{\"string\": \""<<napis<<"\", \"palindrom\": \""<<wartosc<<"\"};\n";			
}

palindrom::~palindrom() {
	plik1.close();
	plik2.close();
}


int main(int argc, char** argv) {
	palindrom p1;
	p1.wczytywanie();
	return 0;
}
