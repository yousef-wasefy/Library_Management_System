#include<iostream>
#include"library_service.h"
using namespace std;

int itemMenu()
{
    int choice;
    cout << "Press:" << endl;
    cout << " 1 to add an item" << endl;
    cout << " 2 to remove an item" << endl;
    cout << " 3 to search for an item by title" << endl;  
    cout << " 0 to exit" << endl;
    cin >> choice;
    return choice;
}

int memberMenu()
{
    int choice;
    cout << "Press:" << endl;
    cout << " 1 to add a member" << endl;
    cout << " 2 to remove a member" << endl;
    cout << " 3 to borrow an item" << endl;
    cout << " 4 to return an item" << endl;   
    cout << " 5 to display borrowed items for a member" << endl;
    cout << " 6 to display all members" << endl;
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
        cout << "Welcome To Library Manange System" << endl;
        cout << "=================================" << endl;
        cout << "Press\n";
        cout << " 1 : item-related matters\n";
        cout << " 2 : Member-related matters\n";
        cout << " 0 : exit\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            switch (itemMenu())
            {          
            case 1:
                library.addItem();
                break;
            case 2:
                library.removeItem();
                break;
            case 3:
                library.searchByTitle();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                answer = 'y';
                continue;
            }
            break;
        case 2:
            switch (memberMenu())
            {
            case 1:
                library.addMember();
                break;
            case 2:
                library.removeMember();
                break;
            case 3:
                library.borrowItem();
                break;
            case 4:
                library.returnItem();
                break;
            case 5:
                library.displayBorrowedItems();
                break;
            case 6:
                library.displayAllMembers();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                answer = 'y';
                continue;
            }
            break;
        case 0:
            library.saveAllToFile();
            return 0;
        }
        
        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    
    library.saveAllToFile();
    return 0;
}