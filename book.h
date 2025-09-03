#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"item.h"

using namespace std;

class book : public item
{
private:
    string publisher;
    int edition = 1;
    int pages = 0;
public:
    book(string pub, int edi, int pags){
        publisher = pub;
        edition = edi;
        pages = pags;
    }

    int getType() override{
        return 1;
    }
    
    void checkout() override{
        item::checkout();
    }
    void checkin() override{
        item::checkin();
    }

    int loanDaysPermitted() override{
        return 21;
    }

    void displayDetails() override {
        item::displayDetails();
        cout << "Publisher: " << publisher << endl;
        cout << "Edition: " << edition << endl;
        cout << "Pages: " << pages << endl;
    }

    void save(ofstream &out) override{
        item::save(out);
        out << publisher << "," << edition << " " << pages << endl;

    }

    void load(ifstream &in) override{
        item::load(in);
        in >> ws; // ignore any whitespace or newline
        getline(in, publisher, ',');
        in >> edition >> pages;
    }
};