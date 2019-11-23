#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <sstream> //konwersja int na str
#include "Uzytkownik.h"
#include "Adresat.h"

using namespace std;

class MetodyPomocnicze {

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    static int konwersjaStringNaInt(string liczba);
    static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
};

#endif // METODYPOMOCNICZE
