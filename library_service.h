#include<iostream>
#include<vector>
#include"item.h"
#include"book.h"
#include"magazine.h"
#include"Item_Repository.h"
#include"member.h"
#include"member_Repo.h"

using namespace std;

class libraryService{
private:
    itemRepo itemsRepo;
    memberRepo membersRepo;
public:
    void addItem(); //DONE
    void removeItem(); //DONE
    void addMember();
    void displayBorrowedItems(); // for a member
    void borrowItem(); //DONE
    void returnItem(); // when an item is returned after borrowing it //DONE
    void searchByTitle(); //DONE
    void overdueLoans();

    void saveAllToFile(){
        itemsRepo.saveToFile();
    }

    void loadAllFromFile(){
        itemsRepo.loadFromFile();
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
            if(Item->checkout()) Member->BorrowedItems(Item);
        }
    }
}

void libraryService::returnItem()
{
    string title;
    cout << "Enter the title of the item you want to return: ";
    cin.ignore();
    getline(cin, title);
    item* Item = itemsRepo.getItemByName(title);
    if (Item == nullptr) cout << "No item found with this title";
    else Item->checkin();
}

void libraryService::addMember()
{
    membersRepo.addMember();
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