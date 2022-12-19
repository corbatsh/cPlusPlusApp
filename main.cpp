#include <iostream>
#include <typeinfo>
#include <fstream>

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

void badCinPrevent() {
    if (cin.bad() || cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void showMenu() {
    cout << "Wybierz opcje z menu:" << endl;
    cout << "[1] Wczytanie kwoty" << endl;
    cout << "[2] Wyświetl dane" << endl;
    cout << "[3] Obliczenia" << endl;
    cout << "[4] Wyszukaj z wybranego przedziału" << endl;
    cout << "[5] Zakończ" << endl;
    cout << "Twój wybór: ";
}

int main() {
    int menuChoice;
    bool addMoreEmployees = true;
    string employeeName[10];
    float employeeSalary[10] = {0};
    cout << "Aplikacja płacowa" << endl << endl;
    do {
        showMenu();
        cin >> menuChoice;
        badCinPrevent();
        if (menuChoice == 5) return 0;
        while (menuChoice > 5 || menuChoice < 1) {
            cout << endl << "Wartość nieprawidłowa! Wybierz jeszcze raz:" << endl << endl;
            break;
        }
        switch (menuChoice) {
            case 1:
                cout << "Your choice is to put new employee data: \n";
                for (int i = 0; i < 10; ++i) {
                    if (employeeSalary[i] == 0) {
                        cout << "Enter employee name: \n";
                        cin >> employeeName[i];
                        cout << "\nEnter employee salary: \n";
                        cin >> employeeSalary[i];

                        cout << "Wants to end? [PRESS 0] Else [PRESS 1] \n";
                        cin >> addMoreEmployees;
                        if (!addMoreEmployees)
                            break;
                    }
                }
            case 2:
                cout << "work in progress1";
                break;
            case 3:
                cout << "work in progress2";
                break;
            case 4:
                cout << "work in progress3";
            case 5:
                break;
            default:
                EXIT_SUCCESS;
        }
    } while (menuChoice >= 1 && menuChoice <= 5);

    return 0;
}
