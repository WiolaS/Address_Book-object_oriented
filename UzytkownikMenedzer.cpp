#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include <windows.h>

using namespace std;

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < uzytkownicy.size(); i++) {
        cout << "Uzytkownik: " << i + 1 << endl;
        cout << "Id: " << uzytkownicy[i].pobierzId() << endl;
        cout << "Login: " << uzytkownicy[i].pobierzLogin() << endl;
        cout << "Haslo: " << uzytkownicy[i].pobierzHaslo() << endl << endl;
    }

}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin (login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    int i = 0;
    while (i < uzytkownicy.size()) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}


void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika) {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}


bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

///getter
int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
