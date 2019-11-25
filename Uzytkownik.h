#ifndef UZYTKOWNIK.H
#define UZYTKOWNIK.H
#include <iostream>

using namespace std;

class Uzytkownik {

    int id;
    string login;
    string haslo;

public:
    Uzytkownik(int id = 0, string login = "", string haslo = "") {
        this->id  = id;
        this->login = login;
        this->haslo = haslo;
    }
    ///settery
    void ustawId (int noweId);
    void ustawLogin (string nowyLogin);
    void ustawHaslo (string noweHaslo);

    ///gettery
    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();

};

#endif // UZYTKOWNIK
