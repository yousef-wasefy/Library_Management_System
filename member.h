#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"item.h"

using namespace std;

class member
{
private:
    int id;
    string name;
    string type; // (student / staff)
    int maxBorrowLimit = 3;
    vector<item*> borrowedItems;
public:
    member(int ID, string Name, string Type) : id(ID), name(Name), type(Type) {}

    bool BorrowedItems(item* newItem);
    bool returnItem(item* Item);
    void displayBorrowedItems();
    bool hasOverdueItems();
    bool canBorrow();

    // -------------

    int getId(){
        return id;
    }
};

bool member::canBorrow()
{
    if (borrowedItems.size() == maxBorrowLimit) return false;
    return true;
}

bool member::BorrowedItems(item* newItem)
{
    if (canBorrow()) {
        borrowedItems.push_back(newItem);
        return true;
    }
    else{
        cout << "This member has reached max borrow limit" << endl;
        return false;
    }
}

bool member::returnItem(item* Item)
{
    for (int i = 0;i < borrowedItems.size();i++){
        if (borrowedItems.at(i) == Item){
            borrowedItems.erase(borrowedItems.begin() + i);
            return true;
        }
    }
    cout << "This item isn't in the borrowed items" << endl;
    return false;
}

void member::displayBorrowedItems()
{
    if (borrowedItems.size() == 0) {
        cout << "No borrowed items for this member";
        return;
    }
    for (int i = 0;i < borrowedItems.size();i++){
        borrowedItems.at(i)->getItemInfos(borrowedItems.at(i));
        cout << "=================" << endl;
    }
}