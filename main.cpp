#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true)
    {
        int wyborUzytkownik = 0;
        int zmiennaLogowania = 0;

        system("cls");
        cout << "    >>> MENU  GLOWNE <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Rejestracja" << endl;
        cout << "2. Logowanie" << endl;
        cout << "9. Koniec programu" << endl;
        cout << "---------------------------" << endl;
        cout << "Twoj wybor: ";
        cin >> wyborUzytkownik;

        switch (wyborUzytkownik)
        {
        case 1:
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case 2:
            zmiennaLogowania = ksiazkaAdresowa.logowanieUzytkownika();

            if(zmiennaLogowania != 0)
            {
                ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
                int wyjscieZPetli = 0;
                while (wyjscieZPetli == 0)
                {
                    int wyborAdresat = 0;
                    system("cls");
                    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
                    cout << "---------------------------" << endl;
                    cout << "1. Dodaj adresata" << endl;
                    cout << "2. Wyswietl adresatow" << endl;
                    cout << "---------------------------" << endl;
                    cout << "7. Zmien haslo" << endl;
                    cout << "8. Wyloguj sie" << endl;
                    cout << "---------------------------" << endl;
                    cout << "Twoj wybor: ";
                    cin >> wyborAdresat;

                    switch (wyborAdresat)
                    {
                    case 1:
                        getchar();//rozwiazanie problemu z dodawaniem adresata (pomija wpisanie imienia)
                        ksiazkaAdresowa.dodajAdresata();
                        break;
                    case 2:
                        ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                        break;
                    case 7:
                        ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                        break;
                    case 8:
                        ksiazkaAdresowa.wylogowanieUzytkownika();
                        wyjscieZPetli = 1;
                        break;
                    }
                }
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
    return 0;
}
