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
    member(int ID, string Name, string Type) : id(ID), name(Name), type(Type){

    }

    void BorrowedItems(item* newItem);
    void returnItem(item* Item);
    void displayBorrowedItems();
    bool hasOverdueItems();
    bool canBorrow();

    // -------

    int getId(){
        return id;
    }
};

void member::BorrowedItems(item* newItem)
{
    borrowedItems.push_back(newItem);
}

void member::displayBorrowedItems()
{
    if (borrowedItems.size() == 0) {
        cout << "No borrowed items for this member";
        return;
    }
    for (int i = 0;i < borrowedItems.size();i++){
        borrowedItems.at(i)->getItemInfos(borrowedItems.at(i));
    }
}