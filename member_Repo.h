#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"item.h"
#include"member.h"

using namespace std;

class memberRepo
{
private:
    vector<member*> members;
public:
    void addMember();
    void removeMember(int id);
    member* findMemberById(int id){
        for (int i = 0;i < members.size();i++){
            if (id == members.at(i)->getId()){
                return members.at(i);
            }
        }
        return nullptr;
    }
    vector<member*> getAllMembers(){
        return members;
    }

    void saveAll();
    void loadAll();
};

void memberRepo::addMember()
{
    cout << "Enter the id of the member: ";
    int id;
    cin >> id;
    cout << "Enter the name of the member: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the type of the member: ";
    string type;
    cin >> type;

    members.push_back(new member(id, name, type));
    cout << "Member added successfully." << endl;
    cout << "Number of members: " << members.size() << endl;
}

void memberRepo::removeMember(int id)
{
    if (findMemberById(id) == nullptr) cout << "No member found with this id" << endl;
    else{
        for (int i = 0;i < members.size();i++){
            if (findMemberById(id) == members.at(i)){
                members.erase(members.begin() + i);
                cout << "This member has been removed" << endl;
                return;
            }
        }
    }
}