#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    int zmiennaLogowania = 0;
    zmiennaLogowania = uzytkownikMenedzer.logowanieUzytkownika();

    if(zmiennaLogowania > 0)
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, zmiennaLogowania);
        //adresatMenedzer->ustawidZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }


    return zmiennaLogowania;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer->dodajAdresata();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresatMenedzer->wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    adresatMenedzer->wyczyscAdresatow();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer -> wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer -> wyszukajAdresatowPoNazwisku();
}

void KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownikow()
{
    while (true)
    {
        char wyborUzytkownik = '0';
        MetodyPomocnicze metodyPomocnicze;

        pokazMenuUzytkownika();
        wyborUzytkownik = metodyPomocnicze.wczytajZnak();

        switch (wyborUzytkownik)
        {
        case '1':
            rejestracjaUzytkownika();
            break;
        case '2':
            wybierzOpcjeZMenuAdresatow();
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
}

void KsiazkaAdresowa::pokazMenuUzytkownika()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}

void KsiazkaAdresowa::wybierzOpcjeZMenuAdresatow()
{
    int zmiennaLogowania = 0;
    MetodyPomocnicze metodyPomocnicze;

    zmiennaLogowania = logowanieUzytkownika();

    if(zmiennaLogowania != 0)
    {
        wczytajAdresatowZalogowanegoUzytkownikaZPliku();
        int wyjscieZPetli = 0;
        getchar();  //przy logowaniu problem z wyswietlaniem info o wczytaniu zbyt wielu charow
        while (wyjscieZPetli == 0)
        {
            char wyborAdresat = '0';
            pokazMenuAdresatow();

            wyborAdresat = metodyPomocnicze.wczytajZnak();

            switch (wyborAdresat)
            {
            case '1':
                dodajAdresata();
                break;
            case '2':
                wyszukajAdresatowPoImieniu();
                break;
            case '3':
                wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                wyswietlWszystkichAdresatow();
                break;
            case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                wylogowanieUzytkownika();
                wyjscieZPetli = 1;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}

void KsiazkaAdresowa::pokazMenuAdresatow()
{
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyswietl adresatow po imieniu" << endl;
    cout << "3. Wyswietl adresatow po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}
