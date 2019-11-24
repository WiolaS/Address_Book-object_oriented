#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Adresat.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class PlikZAdresatami {

    vector <Adresat> adresaci;
    const string nazwaPlikuZAdresatami;


public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {
    };


    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    void wyswietlWszystkichAdresatow(vector <Adresat> adresaci);
    void wyswietlDaneAdresata(Adresat adresat);
    vector <Adresat> pobierzAdresatow();

};

#endif // PLIKZADRESATAMI
