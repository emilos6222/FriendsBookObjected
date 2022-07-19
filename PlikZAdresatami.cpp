#include "PlikZAdresatami.h"

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::out | ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy))
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    int tymczasoweId = 0;
    string tymczasowaDana = "";
    MetodyPomocnicze metodyPomocnicze;

    tymczasoweId = adresat.pobierzId();
    liniaZDanymiAdresata += metodyPomocnicze.konwerjsaIntNaString(tymczasoweId) + '|';
    tymczasoweId = adresat.pobierzIdUzytkownika();
    liniaZDanymiAdresata += metodyPomocnicze.konwerjsaIntNaString(tymczasoweId) + '|';
    tymczasowaDana = adresat.pobierzImie();
    liniaZDanymiAdresata += tymczasowaDana + '|';
    tymczasowaDana = adresat.pobierzNazwisko();
    liniaZDanymiAdresata += tymczasowaDana + '|';
    tymczasowaDana = adresat.pobierzNumerTelefonu();
    liniaZDanymiAdresata += tymczasowaDana + '|';
    tymczasowaDana = adresat.pobierzEmail();
    liniaZDanymiAdresata += tymczasowaDana + '|';
    tymczasowaDana = adresat.pobierzAdres();
    liniaZDanymiAdresata += tymczasowaDana + '|';

    return liniaZDanymiAdresata;
}

void PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in | ios::app);

    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;

    MetodyPomocnicze metodyPomocnicze;
    int idUzytkownika = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    MetodyPomocnicze metodyPomocnicze;
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegAdresata()
{
    Adresat adresat;
    int idOstatniegoAdresata = 0;
    string liniaTekstu = "";
    string tymczasoweID = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in | ios::app);

    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, liniaTekstu))
        {
            int numerZnakuWTekscieOddzielajacego = 0;

            numerZnakuWTekscieOddzielajacego = liniaTekstu.find("|");
            tymczasoweID.assign(liniaTekstu, 0, numerZnakuWTekscieOddzielajacego);
            idOstatniegoAdresata = stoi(tymczasoweID);
        }
        plikTekstowy.close();
        return idOstatniegoAdresata;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
        plikTekstowy.close();
        return idOstatniegoAdresata;
    }

}

void PlikZAdresatami::usunWybranegoAdresataZPliku(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerUsuwanejLinii = 0;
    int numerWczytanejLinii = 1;

    string const nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    string wczytanaLinia = "";

    fstream plikTekstowy, tymczasowyPlikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, wczytanaLinia))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                czyIstniejeAdresat = true;

                if (numerWczytanejLinii == numerUsuwanejLinii)
                {}
                numerUsuwanejLinii = numerWczytanejLinii;
                numerWczytanejLinii++;
            }
            else
            {
                if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
                else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;

                numerWczytanejLinii++;
            }

        }

        if (czyIstniejeAdresat == false)
        {
            plikTekstowy.close();
            tymczasowyPlikTekstowy.close();
            return ;
        }

        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        usunPlik(NAZWA_PLIKU_TEKSTOWEGO);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_TEKSTOWEGO);
        return;
    }

    plikTekstowy.close();
    tymczasowyPlikTekstowy.close();
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::edytujDaneWybranegoAdresataWPliku(Adresat adresat, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    bool czyIstniejeAdresat = false;
    int numerWczytanejLinii = 1;

    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string const nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && tymczasowyPlikTekstowy.good() == true && adresat.pobierzId() != 0)
    {
        while(getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if(adresat.pobierzId() == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;

                czyIstniejeAdresat = true;
                numerWczytanejLinii++;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;

                numerWczytanejLinii++;
            }
        }

        if (czyIstniejeAdresat = false)
        {
            odczytywanyPlikTekstowy.close();
            tymczasowyPlikTekstowy.close();
            return;
        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_TEKSTOWEGO);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_TEKSTOWEGO);
    }
}
