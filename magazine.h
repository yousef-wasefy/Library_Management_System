#pragma once
#include<iostream>
#include<vector>
#include"item.h"

using namespace std;

class magazine : public item
{
private:
    int volume = 0;
    int issueNumber = 0;
    enum Periodicity {Weekly, Monthly, Quarterly, Yearly, Irregular};
    Periodicity periodicty;
    bool currentIssue = false;
    string editorInChief;
public:
    string getIssueInfo();
    bool isBorrowable();
    int loanDaysPermitted() override{
        return 9;
    }
};