#include<iostream>
#include<vector>
#include"item.h"
#include"book.h"
#include"magazine.h"

using namespace std;

class itemRepo
{
private:
    vector<item*>items;
public:
    void addItem();
    void removeItem();

    item* getItemById(int id){
        for (int i = 0;i < items.size();i++){
            if (id == items.at(i)->getId()){
                return items.at(i);
            }
        }
        return nullptr;
    };
    vector<item*>getAllItems(){
        return items;
    };

    void saveToFile();
    void loadFromFile();
};

void itemRepo::addItem(){
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