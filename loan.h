#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include <ctime>
#include"item.h"
#include"member.h"

using namespace std;
using namespace std::chrono;

class loan
{
private:
    int loanId;
    int memberId;
    int itemId;
    system_clock::time_point loanDate;
    system_clock::time_point dueDate;
    system_clock::time_point returnedDate;
    bool returned = false;
public:
    loan(int id, system_clock::time_point loanD, system_clock::time_point dueD, int memberID, int itemID)
    : loanId(id), loanDate(loanD), dueDate(dueD), memberId(memberID), itemId(itemID) {}

    void markReturned(){
        returned = true;
        returnedDate = system_clock::now();
    }

    bool isOverdue(){
        if (returnedDate > dueDate){
            return true;
        }
        return false;
    }

    void displayInfo(){
        cout << "loan id: " << loanId << endl;
        cout << "related for member id: " << memberId << endl;
        cout << "related for item id: " << itemId << endl;

        auto timeNow = system_clock::to_time_t(loanDate);
        cout << "loan date: " << ctime(&timeNow);

        timeNow = system_clock::to_time_t(dueDate);
        cout << "due date: " << ctime(&timeNow);

        timeNow = system_clock::to_time_t(returnedDate);
        cout << "returned date: " << ctime(&timeNow);

        cout << "returned status: " << (returned?"Yes":"NO") << endl;
    }

    void save(ofstream& out){
        out << loanId << " " << memberId << " " << itemId << " " << (returned? "Yes" : "No");

        auto loanTime = system_clock::to_time_t(loanDate);
        auto dueTime = system_clock::to_time_t(dueDate);
        auto returnedTime = system_clock::to_time_t(returnedDate);

        out << " " << ctime(&loanTime) << "," << ctime(&dueTime) << "," << ctime(&returnedTime) << "," << endl;;
    }

    void load(ifstream& in){
        in >> loanId >> memberId >> itemId;

        string str;
        in >> str;
        returned = (str == "Yes");
        in >> ws;

        getline(in, str, ',');
        struct tm TM = {};
        strptime(str.c_str(), "%a %b %d %H:%M:%S %Y", &TM);
        time_t t = mktime(&TM);
        loanDate = system_clock::from_time_t(t);

        getline(in, str, ',');
        strptime(str.c_str(), "%a %b %d %H:%M:%S %Y", &TM);
        t = mktime(&TM);
        dueDate = system_clock::from_time_t(t);

        getline(in, str, ',');
        strptime(str.c_str(), "%a %b %d %H:%M:%S %Y", &TM);
        t = mktime(&TM);
        returnedDate = system_clock::from_time_t(t);
    }

    // -------------------------

    int getId(){
        return loanId;
    }

    int getMemberId(){
        return memberId;
    }

    int getItemId(){
        return itemId;
    }

    system_clock::time_point getLoanDate(){
        return loanDate;
    }

    system_clock::time_point getDueDate(){
        return dueDate;
    }

    bool isReturned(){
        return returned;
    }
};