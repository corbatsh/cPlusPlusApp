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
class Employee {
    int id;
    char name[30];
    float salary;
public:
    void getData();
    void putData();
};
void Employee::putData() {//Defining of function
    cout << "Enter Id : ";
    cin >> id;
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter salary";
    cin >> salary;
}
void Employee::getData(){//Defining of function
    cout << id <<" ";
    cout << name <<" ";
    cout << salary << " ";
    cout<<endl;
}
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



void processMenu(int menuChoice) {
    bool restart;
    int id[10];
    switch (menuChoice) {
        case 1:
            cout << "Your choice is to put new employee data:";
            for(int i = 1; i < sizeof(id); ++i)
            {
                Employee person[sizeof(id)];
                person[i].putData();
            }
            break;
        case 2:
            cout << "work in progress1";
            break;
        case 3:
            cout << "work in progress2";
            break;
        case 4:
            cout << "work in progress3";
        case 5:
            cout << "work in progress4";
        default:
            EXIT_SUCCESS;
    }
}
int main() {
    int menuChoice;
    cout << "Aplikacja płacowa" << endl << endl;
    do {
        showMenu();
        cin >> menuChoice;
        while(menuChoice>5 || menuChoice<1)
        {
            cout << endl << "Wartość nieprawidłowa! Wybierz jeszcze raz:" << endl << endl;
            showMenu();
            cin >> menuChoice;
            if(cin.bad() || cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        processMenu(menuChoice);
    } while (menuChoice >=1 && menuChoice <= 5 );

    return 0;
}
