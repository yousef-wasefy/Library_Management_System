#include<iostream>
#include<vector>
#include"item.h"
#include"book.h"
#include"magazine.h"

using namespace std;

class libraryService{
private:
    vector<item*>items;
public:

    void addBook();

    void addMember();

    void borrowItem();

    void returnItem(); // when an item is returned after borrowing it

    void searchByTitle();

    void overdueLoans();
};

void libraryService::addBook()
{
    cout << "You want to add book or magazine?\nPress (1 for book, 2 for magazine)";
    int choice;
    cin >> choice;

    item *newItem = nullptr;
    switch (choice)
    {
    case 1:
        newItem = new book;
        break;
    case 2:
        newItem = new magazine;
        break;
    }
    
    newItem->setId();
    cout << "Enter the title of the book:";

    newItem->setTitle();
    items.push_back(newItem);
}

void libraryService::searchByTitle()
{
    string title;
    cout << "Enter the title of the book: ";
    cin >> title;
    for (int i = 0;i < items.size();i++)
    {
        if(title == items.at(i)->getTitle())
        {
            cout << "Book found: " << items.at(i)->getTitle() << endl;
            cout << "Book id: " << items.at(i)->getId() << endl;
        }
    }
}