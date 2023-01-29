#include <iostream>
#include <string>

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
    cout << "[3] Calculations" << endl;
    cout << "[4] Search for salary range" << endl;
    cout << "[5] END" << endl;
    cout << "Your choice: ";
}

void bubbleSort(string employeeName[], float employeeSalary[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (employeeSalary[j - 1] > employeeSalary[j]) {
                swap(employeeSalary[j - 1], employeeSalary[j]);
                swap(employeeName[j-1], employeeName[j]);
            }
        }
    }
}

int main() {
    const int memory = 10;
    int menuChoice = 0;
    bool addMoreEmployees = true;
    int employeesWithDataCounter = 0;
    string employeeName[memory];
    float employeeSalary[memory] = {0};
    string indexOfEmployee[memory];
    float salariesSum = 0;
    float salaryRangeMin = 0;
    float salaryRangeMax = 0;
    bool salaryRangeValidationPass = false;
    bool foundInRange = false;
    cout << "PAYROLL APPLICATION" << endl << endl;

    while(menuChoice != 5) {
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
                    cout << "\nPut new employee data: \n\n";
                    for (int i = employeesWithDataCounter; i < memory; ++i) {
                        if (employeeSalary[i] == 0) {
                            cout << "Enter employee name: \n";
                            cin.ignore();
                            getline(cin, employeeName[i]);
                            badCinPrevent();
                            cout << "\nEnter employee salary: \n";
                            cin >> employeeSalary[i];
                            indexOfEmployee[i] = employeeName[i];
                            employeesWithDataCounter++;
                            cout << "Do You want to add more employees? To proceed [PRESS 1] Else [PRESS 0] \n";
                            cin >> addMoreEmployees;
                            if (!addMoreEmployees)
                                break;
                            if (employeesWithDataCounter == memory)
                            {
                                cout << "\nReached the maximum amount of employees! Contact with Administrator\n";
                            }
                        }
                    }
                    bubbleSort(employeeName, employeeSalary, employeesWithDataCounter);
                    break;
                case 2:
                    if (employeesWithDataCounter == 0) {
                        cout << "\nThere is no data provided!\n";
                        break;
                    }
                    cout << endl;
                    for (int i = 0; i < employeesWithDataCounter; ++i) {
                            cout << "[" << i << "] " << employeeName[i] << ": " << employeeSalary[i] << endl;
                    }
                    break;
                case 3:
                    if (employeesWithDataCounter == 0) {
                        cout << "\nThere is no data provided!\n";
                        break;
                    }
                    cout << "\nPick an option from menu below:" << endl;
                    cout << "[1] Sum salaries\n";
                    cout << "[2] Calc average salary\n";
                    cout << "[3] Go back\n";
                    cin >> menuChoice;
                    badCinPrevent();
                    salariesSum = 0;
                    for (int i = 0; i < employeesWithDataCounter; ++i) {
                        salariesSum += employeeSalary[i];
                    }
                    if (menuChoice == 1) {
                        cout << "\nSum of employees salaries totals: " << salariesSum << endl;
                    } else if (menuChoice == 2) {
                        float averageSalary = 0;
                        averageSalary = salariesSum / employeesWithDataCounter;
                        cout << "\nAverage salary totals: " << averageSalary << endl;
                    }
                    break;
                case 4:
                    if (employeesWithDataCounter == 0) {
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
                            cout << "Minimum salary range can't be higher than maximum!\n";
                        }
                    } while (!salaryRangeValidationPass);
                    for (int i = 0; i < memory; ++i) {
                        if (employeeSalary[i] >= salaryRangeMin && employeeSalary[i] <= salaryRangeMax) {
                                foundInRange = true;
                                cout << employeeName[i] << ": " << employeeSalary[i] << endl;
                        }
                    }
                    if (!foundInRange) {
                        cout << "None of the employee salaries meet the requirements\n";
                    }
                    break;
                case 5:
                    break;
                default:
                    EXIT_SUCCESS;
            }
        } while (menuChoice >= 1 && menuChoice <= 5);
    }
    return 0;
}
