#ifndef ADRESAT.H
#define ADRESAT.H
#include <iostream>
#include "Adresat.h"

using namespace std;

class Adresat {
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string numerTelefonu = "", string email = "", string adres = "") {
        this->id  = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }

    ///settery
    void ustawId (int id);
    void ustawIdUzytkownika(int idUzytkownika);
    void ustawImie (string imie);
    void ustawNazwisko (string nazwisko);
    void ustawNumerTelefonu (string numerTelefonu);
    void ustawEmail (string email);
    void ustawAdres (string adres);

    ///gettery
    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

};

#endif // ADRESAT
