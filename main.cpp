#include<iostream>
#include"library_service.h"
using namespace std;

int menu()
{
    int choice;
    cout << "Welcome To Library Manange System" << endl;
    cout << "=================================" << endl;
    cout << "Press 1 to add a book" << endl;
    cout << "Press 2 to search for a book by title" << endl;
    cout << "Press 3 to borrow a book" << endl;
    cout << "Press 4 to return a book" << endl;
    cout << "Press 5 to view overdue loans" << endl;
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
        case 1: library.addBook();
            break;
        case 2: library.searchByTitle();
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            answer = 'y';
            continue;
        }
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    
    return 0;
}