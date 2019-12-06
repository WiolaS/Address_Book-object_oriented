#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H
#include <iostream>
#include <vector>
#include "Adresat.h"


using namespace std;

class PlikTekstowy {
    const string NAZWA_PLIKU;
    const string NAZWA_TYMCZASOWEGO_PLIKU;

public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }
    PlikTekstowy(string nazwaPliku, string nazwaTymczasowegoPliku) : NAZWA_PLIKU(nazwaPliku), NAZWA_TYMCZASOWEGO_PLIKU(nazwaTymczasowegoPliku) {
    }

    string pobierzNazwePliku();
    string pobierzNazweTymczasowegoPliku();
    bool czyPlikJestPusty(fstream &plikTekstowy);

};

#endif // PLIKTEKSTOWY
