#ifndef ADRESAT.H
#define ADRESAT.H
#include <iostream>

using namespace std;

class Adresat {

    int id;
    int idUzytkownika; // przypisaæ w konstruktorze id Uzytkownika
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    ///settery
    void ustawId (int noweId);
    void ustawImie (string noweImie);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTel);
    void ustawEmail (string nowyEmail);
    void ustawAdres (string nowyAdres);

    ///gettery
    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

};

#endif // ADRESAT
