#pragma once
#include<iostream>
#include<vector>
using namespace std;

class item // The Base Class
{
private:
    int id;
    string title;
    string author;
    int year; // year was published
    int totalCopies; // affected only by buying new copies (by the library) (for one item)
    int availableCopies; // affteced by borrow (for one item)

public:
    virtual void checkout(){
        if (availableCopies == 0){
            cout << "Sorry, available copies for this item has finished." << endl;            
        }
        else availableCopies--;
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

    // setters and getters functions

    void setId(){
        static int nextId = 101; // help setting the id automatically
        id = nextId++;
    }

    int getId(){
        return id;
    }

    void setTitle(){
        cin >> title;
    }

    string getTitle(){
        return title;
    }

    void setAuthor(){
        cin >> author;
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