#include "KsiazkaAdresowa.h"
#include <windows.h>
#include <fstream>
#include <sstream> //konwersja int na str

using namespace std;

KsiazkaAdresowa::KsiazkaAdresowa()
{
    nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    dopiszUzytkownikaDoPliku(uzytkownik);

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
    //uzytkownik.haslo = wczytajLinie();  tak by³o
    haslo = wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        //return uzytkownicy.back().id + 1;  tak by³o
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

void KsiazkaAdresowa::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

string KsiazkaAdresowa::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

bool KsiazkaAdresowa::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string KsiazkaAdresowa::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}



