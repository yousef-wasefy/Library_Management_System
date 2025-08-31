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
    void addItem(); //DONE
    void removeItem(); //DONE
    void addMember();
    void borrowItem(); //DONE
    void returnItem(); // when an item is returned after borrowing it //DONE
    void searchByTitle(); //DONE
    void overdueLoans();

    void saveAllToFile(){
        itemsRepo.saveToFile();
    }

    void loadAllFromFile(){
        itemsRepo.loadFromFile();
    }
};

void libraryService::addItem()
{
    itemsRepo.addItem();
}

void libraryService::removeItem()
{
    itemsRepo.removeItem();
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
            tempItems.at(i)->displayDetails();
            return;
        }
    }
    cout << "No item found with this title";
}

void libraryService::borrowItem()
{
    string title;
    cout << "Enter the title of the item you want to borrow: ";
    cin >> title;
    vector<item*> tempItems = itemsRepo.getAllItems();
    for (int i = 0;i < tempItems.size();i++)
    {
        if(title == tempItems.at(i)->getTitle())
        {
            tempItems.at(i)->checkout();
        }
    }
}

void libraryService::returnItem()
{
    string title;
    cout << "Enter the title of the item you want to return: ";
    cin >> title;
    vector<item*> tempItems = itemsRepo.getAllItems();
    for (int i = 0;i < tempItems.size();i++)
    {
        if(title == tempItems.at(i)->getTitle())
        {
            tempItems.at(i)->checkin();
        }
    }
}