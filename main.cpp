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
    cout << endl;
    cout << "Pick an option from menu below:" << endl;
    cout << "[1] Insert employee with salary" << endl;
    cout << "[2] Show data" << endl;
    cout << "[3] calculations" << endl;
    cout << "[4] search for salary range" << endl;
    cout << "[5] END" << endl;
    cout << "Your choice: ";
}

int main() {
    int memory = 10;
    int menuChoice;
    bool addMoreEmployees = true;
    string employeeName[10];
    float employeeSalary[10] = {0};
    float salariesSum = 0;
    int employeesCount = 0;
    cout << "Payroll Application" << endl << endl;
    do {
        showMenu();
        cin >> menuChoice;
        badCinPrevent();
        if (menuChoice == 5) return 0;
        while (menuChoice > 5 || menuChoice < 1) {
            cout << endl << "Invalid Value! Pick again!:" << endl << endl;
            break;
        }
        switch (menuChoice) {
            case 1:
                cout << "Your choice is to put new employee data: \n";
                for (int i = 0; i < memory; ++i) {
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
                cout << endl;
                for (int i = 0; i < memory; ++i) {
                    if (employeeSalary[i] != 0) {
                        cout << employeeName[i] << ": " << employeeSalary[i] << endl;
                    }
                }
                break;
            case 3:
                cout << "Pick an option from menu below:" << endl;
                cout << "[1] Sum salaries\n";
                cout << "[2] calc average salary\n";
                cout << "[3] Go back\n";
                cin >> menuChoice;
                badCinPrevent();
                salariesSum = 0;
                employeesCount = 0;
                for (int i = 0; i < memory; ++i) {

                    if (employeeSalary[i] != 0) {
                        salariesSum += employeeSalary[i];
                        employeesCount++;
                    }

                    if (menuChoice == 1) {
                        cout << "Sum of employees salaries totals: " << salariesSum;
                        break;
                    } else if (menuChoice == 2) {
                        cout << "Average salary totals: " << salariesSum / employeesCount;
                        break;
                    }
                }
                break;
            case 4:
                cout << "work in progress3";
                break;
            case 5:
                break;
            default:
                EXIT_SUCCESS;
        }
    } while (menuChoice >= 1 && menuChoice <= 5);

    return 0;
}
