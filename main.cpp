#include <iostream>
#include <typeinfo>

/*
 * zadeklarować tablicę numeryczną typu float, n elementowa,
 * n - stała define
 * Wczytać z klawiatury dane do tablicy (kwoty), w wersji 2 losowanie wynagrodzenia
 * Na koniec należy wyliczyć kwotę sumaryzcną i średnią i ją wprowadzić.
 *
 * punkt rozwojowy:
 *
 *  Doróbka1:
 *      Stworzenie prostego menuv wyboru:
 *          - wczytanie kwoty
 *          - listing danych, jaki on jest
 *          - obliczenia: suma, średnia
 *          - wyszukiwanie z przedziału z domkniętego przedziału kwot.
 *              Podajemy widelki, min i max. Ma zwrócić znalezioną kwotę, podać jej index, ale
 *              jeśli nie znajdzie ani jednego, to wyświetli komunikat, że takich kwot nie ma.
 *          - Walidacja widełek - najpierw mniejsze, a potem większe. Mogą być równe
 *          - Posortowanie, malejąco lub rosnąco.
 */
using namespace std;

int resetMenu(int choice)
{
    while(choice>5 || choice<1)
    {
        cout<<"Wprowadź prawidłowy wybór " << endl;
        cin >> choice;
    }
}

int main() {
    const int n = 10;
    int choice;
    float salaryArray[n];
    cout << "Aplikacja płacowa" << endl << endl;
    do {
        cout << "Wybierz opcje z menu:" << endl;
        cout << "[1] Wczytanie kwoty" << endl;
        cout << "[2] Wyświetl dane" << endl;
        cout << "[3] Obliczenia" << endl;
        cout << "[4] Wyszukaj z wybranego przedziału" << endl;
        cout << "[5] Zakończ" << endl;
        cout << "Twój wybór: ";
        cin >> choice;
        while(cin.bad() || cin.fail())
        {
            cin.clear();
            cin >> choice;
        }
        resetMenu(choice);
        switch (choice) {
            case 1:
                cout << "test" << endl;
                break;
            case 5:
                return 0;
        }
    } while (choice >=1 && choice <= 5);

    return 0;
}
