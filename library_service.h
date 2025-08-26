#include<iostream>
#include<vector>
#include"item.h"
#include"book.h"
#include"magazine.h"
#include"Item_Repository.h"

using namespace std;

class libraryService{
private:
    itemRepo itemsRepo;
public:
    void addItem();
    void removeItem();
    void addMember();
    void borrowItem();
    void returnItem(); // when an item is returned after borrowing it
    void searchByTitle();
    void overdueLoans();
};

void libraryService::addItem()
{
    itemsRepo.addItem();
}

void libraryService::searchByTitle()
{
    string title;
    cout << "Enter the title of the book: ";
    cin >> title;
    vector<item*> tempItems = itemsRepo.getAllItems();
    for (int i = 0;i < tempItems.size();i++)
    {
        if(title == tempItems.at(i)->getTitle())
        {
            cout << "Book found: " << tempItems.at(i)->getTitle() << endl;
            cout << "Book id: " << tempItems.at(i)->getId() << endl;
        }
    }
}