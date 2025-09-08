#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include"item.h"
#include"member.h"

using namespace std;
using namespace std::chrono;

class loan
{
private:
    int loanId;
    system_clock::time_point loanDate;
    system_clock::time_point dueDate;
    bool returned = false;
public:
    loan(int id, system_clock::time_point loanD, system_clock::time_point dueD, bool Returned)
    : loanId(id), loanDate(loanD), dueDate(dueD), returned(Returned) {}

    void markReturned(){
        returned = true;
    }
    bool isOverdue(){
        auto Now = system_clock::now();
        if (Now > dueDate){
            return true;
        }
        return false;
    }
    void displayInfo(){
        cout << "load id: " << loanId << endl;

        cout << "returned status: " << (returned?"Yes":"NO");
    }

    void save(ofstream& out);
    void load(ifstream& in);
};