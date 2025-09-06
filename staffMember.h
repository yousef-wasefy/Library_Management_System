#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"item.h"
#include"member.h"

using namespace std;

class Staff : public member 
{
private:
    string department;
    int staffId;
    static int nextId;
    int maxBorrowLimit = 7;
public:
    Staff(int ID, string name, int stafId, string dprtment) : member(ID, name), staffId(stafId), department(dprtment){}

    bool canBorrow(int max) override{
        return member::canBorrow(maxBorrowLimit);
    }

    void displayMemberInfos() override {
        member::displayMemberInfos();
        cout << "Staff ID: " << staffId << endl;
        cout << "Department: " << department << endl;
    }

    void setId(){
        staffId = ++nextId;
    }

    int getId(){
        return staffId;
    }

    void save(ofstream &out){
        member::save(out);
        out << staffId << " " << department << "," << endl;
    }

    void load(ifstream &in,itemRepo& itemRepository){
        member::load(in,itemRepository);
        in >> staffId >> ws;
        getline(in, department, ',');
        nextId = staffId;
    }

    int getType(){
        return 2;
    }
};

int Staff::nextId = 1;