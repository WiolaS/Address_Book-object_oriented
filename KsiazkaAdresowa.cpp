#include "KsiazkaAdresowa.h"

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    idZalogowanegoUzytkownika = uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.logowanieUzytkownika());
    adresatMenedzer.pobierzIdOstatniegoAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);

}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer.wyswietlWszystkichAdresatow();
}






