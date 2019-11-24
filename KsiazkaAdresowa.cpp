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
    idZalogowanegoUzytkownika = uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
    adresatMenedzer.pobierzIdOstatniegoAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    cout <<"przed wylogowaniem: " << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
    idZalogowanegoUzytkownika = uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    cout <<"po wylogowaniu: " << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
}

void KsiazkaAdresowa::dodajAdresata()
{

    cout <<"idZalogowanegoUzytkownika: " << idZalogowanegoUzytkownika << endl;
    Sleep(2000);
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);

}

void KsiazkaAdresowa::wyswietlWszystkieKontakty(){
    adresatMenedzer.wyswietlWszystkieKontakty();

}






