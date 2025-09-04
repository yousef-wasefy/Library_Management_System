#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"item.h"
#include"member.h"

using namespace std;

class Student : public member 
{
private:
    int studentId;
    static int nextId;
    int gradeLevel;
    int maxBorrowLimit = 3;
public:
    Student(int ID, string name, int stuId, int grdLevel) : member(ID, name), studentId(stuId), gradeLevel(grdLevel){}

    bool canBorrow(int max) override{
        return member::canBorrow(maxBorrowLimit);
    }

    void displayMemberInfos() override {
        member::displayMemberInfos();
        cout << "Student ID: " << studentId << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }

    void setId(){
        studentId = nextId++;
    }

    int getId(){
        return studentId;
    }
};

int Student::nextId = 1;