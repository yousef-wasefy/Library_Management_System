#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"item.h"

using namespace std;

class magazine : public item
{
private:
    int volume;
    int issueNumber;
    enum Periodicity {Weekly = 1, Monthly, Quarterly, Yearly};
    Periodicity periodicity;
    bool currentIssue = false;
    string editorInChief;
public:
    magazine(int vol, int issNum, int perNum, string editorChief)
    : volume(vol), issueNumber(issNum), editorInChief(editorChief)
    {
        periodicity = (perNum == 1)?Weekly:(perNum == 2)?Monthly:(perNum == 3)?Quarterly:Yearly;
    }

    int getType() override{
        return 2;
    }

    void checkout() override{
        cout << "Enter the volume number: ";
        int vol;
        cin >> vol;
        cout << "Enter the issue number: ";
        int issNum;
        cin >> issNum;
        if ((vol <= volume && issNum < issueNumber) || (vol < volume && issNum == issueNumber)) 
            currentIssue = false;
        else if (vol > volume || (vol == volume && issNum > issueNumber)) {
            cout << "Invalid volume or issue number, please try again" << endl;
            magazine::checkout();
            return;
        }
        else currentIssue = true;

        if (!currentIssue) item::checkout();
        else cout << "This is the current issue, can't borrow it." << endl;
    }

    void checkin() override{
        item::checkin();
    }

    int loanDaysPermitted() override{
        return 9;
    }

    void displayDetails() override {
        item::displayDetails();
        cout << "Volume: " << volume << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Periodicity: ";
        switch (periodicity) {
            case 1: cout << "Weekly"; break;
            case 2: cout << "Monthly"; break;
            case 3: cout << "Quarterly"; break;
            case 4: cout << "Yearly"; break;
        }
        cout << endl;
        cout << "Current Issue: " << (currentIssue ? "Yes" : "No") << endl;
        cout << "Editor-in-Chief: " << editorInChief << endl;
    }

    void save(ofstream &out) override{
        item::save(out);
        out << volume << " " << issueNumber << " " << periodicity << " " << editorInChief << "," << ((currentIssue)?"Yes":"No") << endl;
    }

    void load(ifstream &in) override{
        item::load(in);
        in >> volume >> issueNumber;
        int perNum;
        in >> perNum;
        switch(perNum)
        {
            case 1: periodicity = Weekly; break;
            case 2: periodicity = Monthly; break;
            case 3: periodicity = Quarterly; break;
            case 4: periodicity = Yearly; break;
        }
        
        in >> ws; // ignore any whitespace or newline
        getline(in, editorInChief, ',');
        string currIss;
        in >> currIss;
        currentIssue = (currIss == "Yes");
    }
};