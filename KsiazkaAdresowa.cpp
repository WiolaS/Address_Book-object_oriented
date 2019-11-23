#include "KsiazkaAdresowa.h"
#include <windows.h>


using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    //int idZalogowanego = 0;
    //idZalogowanego = uzytkownikMenedzer.logowanieUzytkownika();
    //uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(idZalogowanego);
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
    adresatMenedzer.pobierzIdOstatniegoAdresata();

}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    cout <<"przed wylogowaniem: " << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    cout <<"po wylogowaniu: " << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
}

void KsiazkaAdresowa::dodajAdresata()
{
    int idZalogowanegoUzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
    cout <<"idZalogowanegoUzytkownika: " << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    Sleep(2000);
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);

}








