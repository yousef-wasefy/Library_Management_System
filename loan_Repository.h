#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include"loan.h"
#include"item.h"
#include"member.h"

using namespace std;

class loanRepo
{
private:
    vector<loan> loans;
public:
    void addLoan();
    void returnLoan(loan Loan);
    loan findLoanById(int loanId);
    vector<loan> getActiveLoans();
    vector<loan> getOverdueLoans();
    void displayAllLoans();
    
    void saveAll();
    void loadAll();
};