#include <iostream>
#include <cstdio>
#include <bitset>

#pragma warning(disable:4996)


using namespace std;

#define Zadanie3

#ifdef Zadanie1

struct Punkt
{
	double x, y;
};

void zapisDoPliku(Punkt tab[], const char* nazwa, const int rozmiar)
{

	FILE* plik = fopen(nazwa, "w+");

	for (int i = 0; i < rozmiar; i++)
	{
		fprintf(plik, "Punkt x: %f; Punkt y: %f\n", tab[i].x, tab[i].y);
	}

	fclose(plik);
}


Punkt odczytajInstancjePliku(const char* nazwa, int instancja)
{
	FILE* plik = fopen(nazwa, "r");
	Punkt punkty;
	int licznik = 1;


	while (!feof(plik) && licznik < instancja) {
		fscanf_s(plik, "Punkt x: %lf; Punkt y: %lf\n", &punkty.x, &punkty.y);
		licznik++;
	}

	fclose(plik);

	return punkty;
}

int main()
{
	const int rozmiar = 5;
	Punkt tablica_wspolrzednych[rozmiar] = { {1,2},{3,4},{5,6},{7,8},{9,10} };

	zapisDoPliku(tablica_wspolrzednych, "punkty.txt", rozmiar);

	cout << "Podaj instancje do oczytu z pliku:" << endl;
	int n;
	cin >> n;

	Punkt wynik = odczytajInstancjePliku("punkty.txt", n);
	cout << "Instancja " << n << ": " << wynik.x << ", " << wynik.y << endl;
}
#endif

#ifdef Zadanie2

void usunZnakiInterpunkcyjne(char* slowo) 
{
	int liczbaznakow = strlen(slowo);
	while (liczbaznakow > 0 && ispunct(slowo[liczbaznakow-1]))
	{
		slowo[liczbaznakow - 1] = '\0';
		liczbaznakow--;
	}
}

void ile_Slow_W_Pliku(const char* nazwa, const char* slowo)
{
	FILE* plik = fopen(nazwa, "r");
	int licznikSlow = 0;

	char aktSlowo[30];
	

	while (plik>>aktSlowo)
	{
		usunZnakiInterpunkcyjne(aktSlowo);
		if (strcmp(slowo,aktSlowo)==0)
		{
			licznikSlow++;
		}
	}

	cout << "Liczba slow w tescie: " << licznikSlow;
}


int main() 
{
	char slowo[] = "Lorem";

	ile_Slow_W_Pliku("slowa.txt", slowo);


}

#endif

#ifdef Zadanie3

enum class Plec 
{
	mezczyzna,
	kobieta
};

enum class Stopien
{
	pierwszy = 1,
	drugi = 2,
	trzeci = 3
};

struct Student 
{
	char imie[40];
	char nazwisko[60];
	Plec plec;
	Stopien stopien;
	int semestr;

};


void studentDoPliku(Student student, const int rozmiar)
{
	FILE* plik = fopen("studet.txt", "r");
	for (int i = 0; i < rozmiar; i++)
	{
		fprintf(plik,"Imie: %s; Nazwisko: %s ");
	}

	fclose(plik);
}

int main()
{

	uint8_t dane = 16;
	uint8_t maska;

	maska = (1 >> 3);

	dane |= maska;
	
	cout << bitset<8>(dane);




}

#endif