#include <iostream>
#include "Adresat.h"
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

    ///settery
    void Adresat::ustawId(int noweId) {
        id = noweId;
    }

    void Adresat::ustawIdUzytkownika(int noweIdUzytkownika) {
        ///noweIdUzytkownika = UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika();
        idUzytkownika = noweIdUzytkownika;
    }

    void Adresat::ustawImie (string noweImie) {
        imie = noweImie;
    }

    void Adresat::ustawNazwisko (string noweNazwisko) {
        nazwisko = noweNazwisko;
    }

    void Adresat::ustawNumerTelefonu (string nowyNumerTel) {
        numerTelefonu = nowyNumerTel;
    }
    void Adresat::ustawEmail (string nowyEmail) {
        email = nowyEmail;
    }
    void Adresat::ustawAdres (string nowyAdres) {
        adres = nowyAdres;
    }


        ///gettery
    int Adresat::pobierzId() {
        return id;
    }
    int Adresat::pobierzIdUzytkownika() {
        return idUzytkownika;
    }
    string Adresat::pobierzImie() {
        return imie;
    }
    string Adresat::pobierzNazwisko() {
        return nazwisko;
    }
    string Adresat::pobierzNumerTelefonu() {
        return numerTelefonu;
    }
    string Adresat::pobierzEmail() {
        return email;
    }
    string Adresat::pobierzAdres() {
        return adres;
    }
