#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PlikTekstowy
{

protected:
    const string NAZWA_PLIKU_TEKSTOWEGO;
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    PlikTekstowy(string nazwaPlikuTekstowego) : NAZWA_PLIKU_TEKSTOWEGO(nazwaPlikuTekstowego)
    {}
};

#endif // PLIKTEKSTOWY_H
