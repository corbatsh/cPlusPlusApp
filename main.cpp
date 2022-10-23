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
void showMenu()
{
    cout << "Wybierz opcje z menu:" << endl;
    cout << "[1] Wczytanie kwoty" << endl;
    cout << "[2] Wyświetl dane" << endl;
    cout << "[3] Obliczenia" << endl;
    cout << "[4] Wyszukaj z wybranego przedziału" << endl;
    cout << "[5] Zakończ" << endl;
    cout << "Twój wybór: ";
}
int main() {
    const int n = 10;
    int choice;
    bool repeat;
   // float salaryArray[n];
    cout << "Aplikacja płacowa" << endl << endl;
    do {
        showMenu();
        cin >> choice;
        while(choice>5 || choice<1)
        {
            cout << endl << "Wartość nieprawidłowa! Wybierz jeszcze raz:" << endl << endl;
            showMenu();
            cin >> choice;
            if(cin.bad() || cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        switch (choice) {
            case 1:
                cout << "test" << endl;
                break;
            case 5:
                return 0;
            default:
                choice = 6;
                repeat = true;
        }
    } while (choice >=1 && choice <= 5);

    return 0;
}
