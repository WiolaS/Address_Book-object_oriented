#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include <windows.h>
#include <fstream>

using namespace std;

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiUzytkownika;
        } else {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << pobierzNazwePliku() << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
    string liniaZDanymiUzytkownika = "";
    MetodyPomocnicze metodyPomocnicze;

    liniaZDanymiUzytkownika += metodyPomocnicze.konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku() {
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik uzytkownik;
    fstream plikTekstowy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami)) {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }

    }
    plikTekstowy.close();

    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejUzytkownika) {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}


void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy) {
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out);

    if (plikTekstowy.good() == true) {
        for (int i = 0; i < uzytkownicy.size(); i++) {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownicy[i]);

            if (i == uzytkownicy.size()) {
                plikTekstowy << liniaZDanymiUzytkownika;
            } else {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << pobierzNazwePliku() << endl;
    }
    plikTekstowy.close();
}
