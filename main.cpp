#include <iostream>
#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"
#include <cstdlib>

using namespace std;


int main() {
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt", "TymczasowiAdresaci.txt");
    char wybor;

    while (true) {
        if (!(ksiazkaAdresowa.czyUzytkownikJestZalogowany())) {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else if (ksiazkaAdresowa.czyUzytkownikJestZalogowany()) {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                break;
            }
        }
    }
    return 0;

}





    /* KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
     ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
     ksiazkaAdresowa.rejestracjaUzytkownika();
     ksiazkaAdresowa.rejestracjaUzytkownika();

     ksiazkaAdresowa.logowanieUzytkownika();
     ksiazkaAdresowa.dodajAdresata();
     ksiazkaAdresowa.dodajAdresata();
     ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
     ksiazkaAdresowa.wyswietlWszystkichAdresatow();
     ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
     ksiazkaAdresowa.wylogujUzytkownika();
     ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

     ksiazkaAdresowa.logowanieUzytkownika();
     ksiazkaAdresowa.dodajAdresata();
     ksiazkaAdresowa.wyswietlWszystkichAdresatow();
     ksiazkaAdresowa.wylogujUzytkownika();*/



