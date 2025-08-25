#include<iostream>
#include<vector>
#include"item.h"

using namespace std;

class libraryService{
private:
    vector<item> items;
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
    item newItem;
    newItem.setId();
    cout << "Enter the title of the book: ";
    newItem.setTitle();
    items.push_back(newItem);
}

void libraryService::searchByTitle()
{
    string title;
    cout << "Enter the title of the book: ";
    cin >> title;
    for (int i = 0;i < items.size();i++)
    {
        if(title == items.at(i).getTitle())
        {
            cout << "Book found: " << items.at(i).getTitle() << endl;
            cout << "Book id: " << items.at(i).getId() << endl;
        }
    }
}