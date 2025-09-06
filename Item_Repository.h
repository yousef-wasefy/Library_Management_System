#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"item.h"
#include"book.h"
#include"magazine.h"

using namespace std;

class itemRepo
{
private:
    vector<item*>items;
public:
    void addItem(); //DONE
    void removeItem(); //DONE

    item* getItemById(int id){
        for (int i = 0; i < items.size(); i++){
            if (id == items.at(i)->getId()){
                return items.at(i);
            }
        }
        return nullptr;
    };

    item* getItemByName(string title){
        for (int i = 0; i < items.size(); i++){
            if (title == items.at(i)->getTitle()){
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

    for (int i = 0;i < 1;i++){
        item *newItem = nullptr;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the publisher of the book: ";
            string publisher;           
            cin.ignore();
            getline(cin, publisher);
            cout << "Enter the edition of the book: ";
            int edition;
            cin >> edition;
            cout << "Enter the pages of the book: ";
            int pages;
            cin >> pages;
            newItem = new book(publisher, edition, pages);
            break;
        }
        case 2:
        {
            cout << "Enter periodicity (1:Weekly, 2:Monthly, 3:Quarterly, 4:Yearly)\n";
            cout << "Enter the number: ";
            enum periodicity {Weekly = 1, Monthly, Quarterly, Yearly};
            int perNum;
            cin >> perNum;
            if (perNum < 1 || perNum > 4) {
                cout << "Invalid periodicity selectedو defaulting to monthly.\n";
                perNum = 2;
            }

            int vol, issNum;
            cout << "Enter the volume number: ";
            cin >> vol;
            cout << "Enter the issue number: ";
            cin >> issNum;

            cout << "Enter the editor-in-chief: ";
            string editorChief;
            cin.ignore();
            getline(cin, editorChief);
                
            newItem = new magazine(vol, issNum, perNum, editorChief);
            break;
        }
        }
        newItem->setId();

        cout << "Enter the title of the book: ";
        newItem->setTitle();
        cout << "Enter the year was published: ";
        newItem->setYear();
        cout << "Enter the author: ";
        newItem->setAuthor();
        cout << "Enter the total copies: ";
        newItem->setTotalCopies();
        cout << "Enter the available copies: ";
        newItem->setAvailableCopies();

        items.push_back(newItem);
    }
    cout << "Item added successfully.\n";
    cout << "Number of items: " << items.size() << endl;
}

void itemRepo::removeItem()
{
    cout << "Enter the id of the item to remove: ";
    int id;
    cin >> id;
    for (int i = 0;i < items.size();i++){
        if (id == items.at(i)->getId()){
            items.erase(items.begin() + i);         
        }
    }
    cout << "Item removed successfully.\n";
    cout << "Number of items: " << items.size() << endl;
}

void itemRepo::saveToFile()
{  
    ofstream out;
    out.open("library_file.txt");

    out << items.size() << " ";
    for (int i = 0;i < items.size();i++){
        items.at(i)->save(out);
    }

    out.close();
    cout << "All items saved successfully.\n";
}

void itemRepo::loadFromFile()
{
    ifstream in("library_file.txt");

    int n;
    in >> n; // = items.size()
    items.clear();

    int type;
    for (int i = 0; i < n; i++) {
        in >> type;
        item* newItem = nullptr;
        switch (type)
        {
        case 1:
            newItem = new book("", 0, 0);
            break;
        case 2:
            newItem = new magazine(0, 0, 0, "");
            break;
        default:
            cout << "Error loading item type." << endl;
            return;
        }
        newItem->load(in);
        items.push_back(newItem);
    }

    in.close();
    cout << "All items loaded successfully.\n";
}