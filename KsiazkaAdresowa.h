#ifndef KSIAZKAADRSOWA_H
#define KSIAZKAADRSOWA_H
#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {


    //int idUsunietegoAdresata;
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

    int idZalogowanegoUzytkownika;


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer (nazwaPlikuZAdresatami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkieKontakty();



};

#endif // KSIAZKAADRSOWA
