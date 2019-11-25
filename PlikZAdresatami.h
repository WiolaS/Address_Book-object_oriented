#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <vector>
#include "Adresat.h"


using namespace std;

class PlikZAdresatami {

    vector <Adresat> adresaci;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata = 0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();

    vector <Adresat> pobierzAdresatow();

};

#endif // PLIKZADRESATAMI
