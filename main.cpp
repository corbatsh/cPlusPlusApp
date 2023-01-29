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

void bubbleSort(float tab[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (tab[j - 1] > tab[j]) {
                swap(tab[j - 1], tab[j]);
            }
        }
    }
}

int main() {
    const int memory = 10;
    int menuChoice;
    bool addMoreEmployees = true;
    int employeesWithDataCounter = 0;
    string employeeName[memory];
    float employeeSalary[memory] = {0};
    float salariesSum = 0;
    float salaryRangeMin = 0;
    float salaryRangeMax = 0;
    bool salaryRangeValidationPass = false;
    bool foundInRange = false;
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
                        employeesWithDataCounter++;
                        cout << "Do You want to add more employees? To proceed [PRESS 1] Else [PRESS 0] \n";
                        cin >> addMoreEmployees;
                        if (!addMoreEmployees)
                            break;
                    }
                }
                bubbleSort(employeeSalary, employeesWithDataCounter);
                break;
            case 2:
                if (employeesWithDataCounter == 0)
                {
                    cout << "\nThere is no data provided!\n";
                    break;
                }
                cout << endl;
                for (int i = 0; i < memory; ++i) {
                    if (employeeSalary[i] != 0) {
                        cout << employeeName[i] << ": " << employeeSalary[i] << endl;
                    }
                }
                break;
            case 3:
                if (employeesWithDataCounter == 0)
                {
                    cout << "\nThere is no data provided!\n";
                    break;
                }
                cout << "Pick an option from menu below:" << endl;
                cout << "[1] Sum salaries\n";
                cout << "[2] calc average salary\n";
                cout << "[3] Go back\n";
                cin >> menuChoice;
                badCinPrevent();
                salariesSum = 0;
                for (int i = 0; i < employeesWithDataCounter; ++i) {
                    salariesSum += employeeSalary[i];
                }
                if (menuChoice == 1) {
                    cout << "Sum of employees salaries totals: " << salariesSum;
                } else if (menuChoice == 2) {
                    float averageSalary = 0;
                    averageSalary = salariesSum / employeesWithDataCounter;
                    cout << "Average salary totals: " << averageSalary;
                }
                break;
            case 4:
                if (employeesWithDataCounter == 0)
                {
                    cout << "\nThere is no data provided!\n";
                    break;
                }
                do {
                    cout << "Search for salary range:\n\n";
                    cout << "Enter minimum range of salary\n";
                    cin >> salaryRangeMin;
                    badCinPrevent();
                    cout << "Enter maximum range of salary\n";
                    cin >> salaryRangeMax;
                    badCinPrevent();
                    if (salaryRangeMin <= salaryRangeMax) {
                        salaryRangeValidationPass = true;
                    } else {
                        cout << "minimum salary range can't be higher than maximum!\n";
                    }
                } while (!salaryRangeValidationPass);
                for (int i = 0; i < memory; ++i) {
                    if (employeeSalary[i] >= salaryRangeMin && employeeSalary[i] <= salaryRangeMax) {
                        if (employeeSalary[i] != 0) {
                            foundInRange = true;
                            cout << employeeName[i] << ": " << employeeSalary[i] << endl;
                        }
                    }
                }
                if (!foundInRange) {
                    cout << "None of the employees salaries meet the requirements\n";
                }
                break;
            case 5:
            default:
                EXIT_SUCCESS;
        }
    } while (menuChoice >= 1 && menuChoice <= 5);

    return 0;
}
