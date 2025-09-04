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
    static int nextId;
    string name;
    int maxBorrowLimit;
    vector<item*> borrowedItems;
public:
    member(int ID, string Name) : id(ID), name(Name) {}

    void BorrowedItems(item* newItem);
    void returnItem(item* Item);
    void displayBorrowedItems();
    bool hasOverdueItems();
    virtual bool canBorrow(int max);

    virtual void displayMemberInfos() {
        cout << "Member ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Number of Borrowed Items: " << borrowedItems.size() << endl;
    }

    // -------------

    void setId(){
        id = nextId++;
    }

    int getId(){
        return id;
    }
};

bool member::canBorrow(int max)
{
    maxBorrowLimit = max;
    if (borrowedItems.size() == maxBorrowLimit) return false;
    return true;
}

void member::BorrowedItems(item* newItem)
{
    if (newItem->getAvailableCopies() == 0){
        cout << "Sorry, available copies for this item has finished." << endl;
    }
    else {
        if (canBorrow(maxBorrowLimit)) {
            borrowedItems.push_back(newItem);
            newItem->checkout();
        }
        else{
            cout << "This member has reached max borrow limit" << endl;
        }
    }
}

void member::returnItem(item* Item)
{
    if (Item->getAvailableCopies() == Item->getTotalCopies()){
        cout << "All copies are already in the library." << endl;
        return;
    }
    for (int i = 0;i < borrowedItems.size();i++){
        if (borrowedItems.at(i) == Item){
            borrowedItems.erase(borrowedItems.begin() + i);
            Item->checkin();
            return;
        }
    }
    cout << "This item isn't in the borrowed items" << endl;
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

int member::nextId = 2025101;