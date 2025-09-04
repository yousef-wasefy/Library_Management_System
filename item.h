#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class item // The Base Class
{
private:
    int id;
    static int nextId; // help setting the id automatically
    string title;
    string author;
    int year; // year was published
    int totalCopies; // affected only by buying new copies (by the library) (for one item)
    int availableCopies; // affteced by borrow (for one item)

public:
    virtual void checkout(){
        availableCopies--;
        cout << "Checked out successfully, available copies: " << availableCopies << endl;    
    }
    virtual void checkin(){
        availableCopies++;
        cout << "Checked in successfully, available copies: " << availableCopies << endl;
    }
    virtual int loanDaysPermitted() = 0;

    virtual void displayDetails() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year Published: " << year << endl;
        cout << "Total Copies: " << totalCopies << endl;
        cout << "Available Copies: " << availableCopies << endl;
    }

    virtual void getItemInfos(item* Item)
    {
        cout << "item title: " << Item->getTitle() << endl;
        cout << "item author: " << Item->getAuthor() << endl;      
    }

    virtual int getType() = 0;

    // save and load functions
    virtual void save(ofstream &out){

        out << getType() << " " << id << " " <<  title << "," << author << "," << year << " ";
        out << availableCopies << " " << totalCopies << " ";

    }

    virtual void load(ifstream &in){
        in >> id >> ws;
        getline(in, title, ',');
        getline(in, author, ',');
        in >> year >> availableCopies >> totalCopies;
        nextId = id;
    }

    // setters and getters functions

    void setId(){
        id = ++nextId;
    }

    int getId(){
        return id;
    }

    void setTitle(){
        cin.ignore();
        getline(cin, title);
    }

    string getTitle(){
        return title;
    }

    void setAuthor(){
        cin.ignore();
        getline(cin, author);
    }

    string getAuthor(){
        return author;
    }

    void setYear(){
        cin >> year;
    }

    int getYear(){
        return year;
    }

    void setTotalCopies(){
        cin >> totalCopies;
    }

    int getTotalCopies(){
        return totalCopies;
    }

    void setAvailableCopies(){
        cin >> availableCopies;
    }

    int getAvailableCopies(){
        return availableCopies;
    }
};

int item::nextId = 0;