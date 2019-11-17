#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H
#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    PlikZUzytkownikami plikZUzytkownikami;


public:
    void rejestracjaUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();


    void wypiszWszystkichUzytkownikow();

};

#endif // UZYTKOWNIKMENEDZER
