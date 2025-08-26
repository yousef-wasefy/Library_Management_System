#pragma once
#include<iostream>
#include<vector>
#include"item.h"

using namespace std;

class book : public item
{
private:
    string publisher;
    int edition = 1;
    int pages = 0;
public:
    string getSummary(); // return title + author + year
    void displayDetails(); // return all infos
    int loanDaysPermitted() override{
        return 21;
    }
};