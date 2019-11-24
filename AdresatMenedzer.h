#ifndef ADRESATMEMEDZER_H
#define ADRESATMEMEDZER_H
#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata;

    public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {
    };

    int pobierzIdOstatniegoAdresata(int idZalogowanegoUzytkownika);
    int dodajAdresata(int idZalogowanegoUzytkownika);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkieKontakty();
    void pobierzAdresatow();

};


#endif // ADRESATMEMEDZER
