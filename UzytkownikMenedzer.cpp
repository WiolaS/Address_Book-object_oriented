#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include <windows.h>


using namespace std;

//setter
int UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika (int idZalogowanegoU) {
    idZalogowanegoUzytkownika = idZalogowanegoU;
    return idZalogowanegoUzytkownika;
}

///getter
int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

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

    //uzytkownik.id = pobierzIdNowegoUzytkownika();   tak by³o
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());


    string login;
    do {
        cout << "Podaj login: ";
        ///uzytkownik.login = wczytajLinie();
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin (login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    //uzytkownik.haslo = wczytajLinie();  tak by³o
    haslo = MetodyPomocnicze::wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        //return uzytkownicy.back().id + 1;  tak by³o
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

void UzytkownikMenedzer::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}




int UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    //vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    int i = 0;
    while (i < uzytkownicy.size()) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return uzytkownicy[i].pobierzId();
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

