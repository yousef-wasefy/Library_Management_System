#include<iostream>
#include<vector>
#include"item.h"
#include"Item_Repository.h"
#include"member.h"
#include"member_Repo.h"
#include"loan.h"
#include"loan_Repository.h"

using namespace std;

class libraryService{
private:
    itemRepo itemsRepo;
    memberRepo membersRepo;
    loanRepo loansRepo;
public:
    void addItem(); //DONE
    void removeItem(); //DONE
    void addMember(); //DONE
    void removeMember(); //DONE
    void displayBorrowedItems(); // for a member //DONE
    void borrowItem(); //DONE
    void returnItem(); // when an item is returned after borrowing it //DONE
    void searchByTitle(); //DONE
    void overdueLoans();
    void activeLoans();
    void displayAllLoans();
    
    void displayAllMembers(){
        membersRepo.displayAllMembers();
    }

    void saveAllToFile(){
        itemsRepo.saveToFile();
        membersRepo.saveAll();
        loansRepo.saveAll();
    }

    void loadAllFromFile(){
        itemsRepo.loadFromFile();
        membersRepo.loadAll(itemsRepo);
        loansRepo.loadAll();
    }
};

void libraryService::addItem()
{
    itemsRepo.addItem();
}

void libraryService::removeItem()
{
    itemsRepo.removeItem();
}

void libraryService::searchByTitle()
{
    string title;
    cout << "Enter the title of the book: ";
    cin.ignore();
    getline(cin, title);
    item* Item = itemsRepo.getItemByName(title);
    if (Item == nullptr) cout << "No item found with this title";
    else Item->displayDetails();
}

void libraryService::borrowItem()
{
    cout << "Enter the id of the member who want to borrow: ";
    int id;
    cin >> id;
    member* Member = membersRepo.findMemberById(id);
    if(Member == nullptr) cout << "No member found with this id";
    else {
        string title;
        cout << "Enter the title of the item you want to borrow: ";
        cin.ignore();
        getline(cin, title);
        item* Item = itemsRepo.getItemByName(title);
        if (Item == nullptr) cout << "No item found with this title";
        else {
            if(Member->BorrowedItems(Item)) loansRepo.addLoan(Member->getId(), Item->getId());
        }
    }
}

void libraryService::returnItem()
{
    cout << "Enter the id of the member who want to return: ";
    int id;
    cin >> id;
    member* Member = membersRepo.findMemberById(id);
    if(Member == nullptr) cout << "No member found with this id";
    else {
        string title;
        cout << "Enter the title of the item you want to return: ";
        cin.ignore();
        getline(cin, title);
        item* Item = itemsRepo.getItemByName(title);
        if (Item == nullptr) cout << "No item found with this title";
        else {
            if(Member->returnItem(Item)) loansRepo.returnLoan(Member->getId(), Item->getId());
        }
    }
}

void libraryService::addMember()
{
    membersRepo.addMember();
}

void libraryService::removeMember()
{
    cout << "Enter the id of the member: ";
    int id;
    cin >> id;
    membersRepo.removeMember(id);
}

void libraryService::displayBorrowedItems()
{
    cout << "Enter the id of the member: ";
    int id;
    cin >> id;
    member* Member = membersRepo.findMemberById(id);
    if (Member == nullptr) cout << "No member found with this id";
    else {
        Member->displayBorrowedItems();
    }
}

void libraryService::overdueLoans()
{
    vector<loan*> Loans = loansRepo.getOverdueLoans();
    for (int i = 0;i < Loans.size();i++){
        Loans.at(i)->displayInfo();
        cout << "================" << endl;
    }
}

void libraryService::activeLoans()
{
    vector<loan*> Loans = loansRepo.getActiveLoans();
    for (int i = 0;i < Loans.size();i++){
        Loans.at(i)->displayInfo();
        cout << "================" << endl;
    }
}

void libraryService::displayAllLoans()
{
    loansRepo.displayAllLoans();
}