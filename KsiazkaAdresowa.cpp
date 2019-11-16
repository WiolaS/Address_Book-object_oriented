#include "KsiazkaAdresowa.h"
#include <windows.h>

using namespace std;

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika();   tak by³o
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());


    string login;
    do
    {
        cout << "Podaj login: ";
        ///uzytkownik.login = wczytajLinie();
        login = wczytajLinie();
        uzytkownik.ustawLogin (login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    //uzytkownik.haslo = wczytajLinie();
    haslo = wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        //return uzytkownicy.back().id + 1;
        return uzytkownicy.back().pobierzId() + 1;
}

bool KsiazkaAdresowa::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
           cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

string KsiazkaAdresowa::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void KsiazkaAdresowa::wypiszWszytskichUzytkownikow() {
    for (int i = 0; i < uzytkownicy.size(); i++) {
        cout << "Uzytkownik: " << i + 1 << endl;
        cout << "Id: " << uzytkownicy[i].pobierzId() << endl;
        cout << "Login: " << uzytkownicy[i].pobierzLogin() << endl;
        cout << "Haslo: " << uzytkownicy[i].pobierzHaslo() << endl << endl;
    }

}



