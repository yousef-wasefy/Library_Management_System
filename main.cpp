#include<iostream>
#include"library_service.h"
using namespace std;

int menu()
{
    int choice;
    cout << "Welcome To Library Manange System" << endl;
    cout << "=================================" << endl;
    cout << "Press 1 to add an item" << endl;
    cout << "Press 2 to search for an item by title" << endl;
    cout << "Press 3 to borrow an item" << endl;
    cout << "Press 4 to return an item" << endl;
    cout << "Press 5 to remove an item" << endl;
    cout << "Press 6 to view overdue loans" << endl;
    cout << "Press 0 to exit" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    libraryService library;

    char answer;
    do
    {
        switch (menu())
        {
        case 1: library.addItem();
            break;
        case 2: library.searchByTitle();
            break;
        case 3: library.borrowItem();
            break;
        case 4: library.returnItem();
            break;
        case 5: library.removeItem();
            break;
        case 0: return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
            answer = 'y';         
            continue;
        }
        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    
    return 0;
}