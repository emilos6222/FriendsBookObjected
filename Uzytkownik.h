#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

public:
    void ustawId(int noweID);
    void ustawLogin(string login);
    void ustawhaslo(string haslo);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif // UZYTKOWNIK_H
