#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include"loan.h"
#include"item.h"
#include"member.h"

using namespace std;
using namespace std::chrono;

class loanRepo
{
private:
    vector<loan*> loans;
public:
    void addLoan(int memberId, int itemId);
    void returnLoan(int memberId, int itemId);
    loan* findLoanById(int loanId);
    vector<loan*> getActiveLoans();
    vector<loan*> getOverdueLoans();
    void displayAllLoans();
    
    void saveAll();
    void loadAll();
};

void loanRepo::addLoan(int memberId, int itemId)
{
    int id = loans.empty() ? 1 : loans.back()->getId() + 1;

    system_clock::time_point now = system_clock::now();

    loans.push_back(new loan(id, now, now + chrono::minutes(2), memberId, itemId));

    cout << "loan added succesfully" << endl;
}

void loanRepo::returnLoan(int memberId, int itemId)
{
    vector<loan*> actLoans = getActiveLoans();
    for (int i = 0;i < actLoans.size();i++){
        if (actLoans.at(i)->getMemberId() == memberId && actLoans.at(i)->getItemId() == itemId){
            actLoans.at(i)->markReturned();
            return;
        }
    }
}

loan* loanRepo::findLoanById(int loanId)
{
    for (int i = 0;i < loans.size();i++){
        if (loanId == loans.at(i)->getId()) return loans.at(i);
    }
    return nullptr;
}

vector<loan*> loanRepo::getActiveLoans()
{
    vector<loan*> activeLoans;
    for (int i = 0;i < loans.size();i++){
        if (loans.at(i)->isReturned() == false) activeLoans.push_back(loans.at(i));
    }
    return activeLoans;
}

vector<loan*> loanRepo::getOverdueLoans()
{
    vector<loan*> overdueLoans;
    for (int i = 0;i < loans.size();i++){
        if (loans.at(i)->isOverdue()) overdueLoans.push_back(loans.at(i));
    }
    return overdueLoans;
}

void loanRepo::displayAllLoans()
{
    for (int i = 0;i < loans.size();i++){
        loans.at(i)->displayInfo();
        cout << "================" << endl;
    }
}

void loanRepo::saveAll()
{
    ofstream out;
    out.open("loans.txt");

    out << loans.size() << " ";

    for (int i = 0;i < loans.size();i++){
        loans.at(i)->save(out);
    }

    out.close();
    cout << "Loans saved successfully" << endl;
}

void loanRepo::loadAll()
{
    ifstream in;
    in.open("loans.txt");

    int size;
    in >> size;

    for (int i = 0;i < size;i++){
        loans.push_back(new loan(0, system_clock::now(), system_clock::now(), 0 ,0));
        loans.at(i)->load(in);
    }

    in.close();
    cout << "Loans loaded successfully" << endl;
}

