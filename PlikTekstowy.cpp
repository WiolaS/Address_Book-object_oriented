#include "PlikTekstowy.h"
#include "fstream"

using namespace std;

bool PlikTekstowy::czyPlikJestPusty(fstream &plikTekstowy) {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}

string PlikTekstowy::pobierzNazweTymczasowegoPliku()
{
    return NAZWA_TYMCZASOWEGO_PLIKU;
}

