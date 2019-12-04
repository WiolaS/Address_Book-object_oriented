#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"
#include <windows.h> //system("cls")
#include <algorithm>

using namespace std;

/*int AdresatMenedzer::pobierzIdOstatniegoAdresata(int idZalogowanegoUzytkownika) {
    idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    adresaci = plikZAdresatami.pobierzAdresatow();
    return idOstatniegoAdresata;
}*/

int AdresatMenedzer::dodajAdresata() {
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
        cout << "Nowy adresat zostal dodany" << endl;
    }
    else
        cout << " Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

int AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

     for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.edytujLubUsunZPlikuWybranegoAdresata(adresaci[i], 0);
                adresaci.erase(adresaci.begin() + i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}



int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}


void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                plikZAdresatami.edytujLubUsunZPlikuWybranegoAdresata(0, adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                plikZAdresatami.edytujLubUsunZPlikuWybranegoAdresata(0, adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujLubUsunZPlikuWybranegoAdresata(0, adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujLubUsunZPlikuWybranegoAdresata(0, adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujLubUsunZPlikuWybranegoAdresata(0, adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}



