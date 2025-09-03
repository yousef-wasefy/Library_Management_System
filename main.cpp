#include<iostream>
#include"library_service.h"
using namespace std;

int menu()
{
    int choice;
    cout << "Welcome To Library Manange System" << endl;
    cout << "=================================" << endl;
    cout << "Press:" << endl;
    cout << " 1 to add an item" << endl;
    cout << " 2 to remove an item" << endl;
    cout << " 3 to search for an item by title" << endl;
    cout << " 4 to add a member" << endl;
    cout << " 5 to borrow an item" << endl;
    cout << " 6 to return an item" << endl;   
    cout << " 7 to display borrowed items for a member" << endl;
    cout << " 8 to remove a member" << endl;
    cout << " 9 to view overdue loans" << endl;
    cout << " 0 to exit" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    libraryService library;

    library.loadAllFromFile();

    char answer;
    do
    {
        switch (menu())
        {
        case 1: library.addItem();
            break;
        case 2: library.removeItem();
            break;
        case 3: library.searchByTitle();
            break;
        case 4: library.addMember();
            break;
        case 5: library.borrowItem();
            break;
        case 6: library.returnItem();
            break;
        case 7: library.displayBorrowedItems();
            break;
        case 8: library.removeMember();
            break;
        case 0: library.saveAllToFile();
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
            answer = 'y';
            continue;
        }
        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    
    library.saveAllToFile();
    return 0;
}