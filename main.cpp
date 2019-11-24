#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.dodajAdresata();
   // ksiazkaAdresowa.dodajAdresata();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.wyswietlWszystkieKontakty();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

   // ksiazkaAdresowa.wylogujUzytkownika();
    //ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkieKontakty();
    //ksiazkaAdresowa.wylogujUzytkownika();


    return 0;

}
