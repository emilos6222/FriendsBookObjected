#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegAdresata();

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    //getchar();

    cout << "Podaj imie: ";
    string tymczasowaDana = "";
    MetodyPomocnicze metodyPomocnicze;

    tymczasowaDana = metodyPomocnicze.wczytajLinie();
    tymczasowaDana = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(tymczasowaDana);
    adresat.ustawImie(tymczasowaDana);

    cout << "Podaj nazwisko: ";
    tymczasowaDana = metodyPomocnicze.wczytajLinie();
    tymczasowaDana = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(tymczasowaDana);
    adresat.ustawNazwisko(tymczasowaDana);

    cout << "Podaj numer telefonu: ";
    tymczasowaDana = metodyPomocnicze.wczytajLinie();
    adresat.ustawNumerTelefonu(tymczasowaDana);

    cout << "Podaj email: ";
    tymczasowaDana = metodyPomocnicze.wczytajLinie();
    adresat.ustawEmail(tymczasowaDana);

    cout << "Podaj adres: ";
    tymczasowaDana = metodyPomocnicze.wczytajLinie();
    adresat.ustawAdres(tymczasowaDana);

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId()<< endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::dopiszAdresataDoPliku(Adresat adresat)
{
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

//void AdresatMenedzer::ustawidZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
//{
//    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
//}

void AdresatMenedzer::wyczyscAdresatow()
{
    adresaci.clear();
}
