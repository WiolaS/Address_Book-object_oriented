#ifndef KSIAZKAADRSOWA_H
#define KSIAZKAADRSOWA_H
#include <iostream>
#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa {

    //int idOstatniegoAdresata;
    //int idUsunietegoAdresata;
    UzytkownikMenedzer uzytkownikMenedzer;

public:
   void rejestracjaUzytkownika();
   void wypiszWszystkichUzytkownikow();
};

#endif // KSIAZKAADRSOWA
