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
        staffId = nextId++;
    }

    int getId(){
        return staffId;
    }
};

int Staff::nextId = 1;