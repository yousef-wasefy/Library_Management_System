#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"member.h"
#include"studentMember.h"
#include"staffMember.h"

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

    void displayAllMembers() {
        for (auto member : members) {
            member->displayMemberInfos();
            cout << "=================" << endl;
        }
    }

    void saveAll();
    void loadAll();
};

void memberRepo::addMember()
{
    member* Member;

    cout << "Enter the name of the member: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Enter the type of the member (1: Student, 2: Staff)\n";
    cout << "Enter a number: ";
    int type;
    cin >> type;
    switch (type)
    {
    case 1:
    {
        Student student(0,name,0,0);
        student.setId();
        int stuId = student.getId();
        cout << "Enter the grade level: ";
        int grdLevel;
        cin >> grdLevel;
        Member = new Student(0, name, stuId, grdLevel);
        break;
    }
    case 2:
    {
        Staff staff(0,name,0,"");

        cout << "Enter the department\n";
        string dprtment;
        cout << "1: Science\n2: Arts\n3: Commerce\n4: Sports\n5: Others\n";
        int deptNum;
        cin >> deptNum;
        switch (deptNum)
        {
        case 1:
            dprtment = "Science";
            break;
        case 2:
            dprtment = "Arts";
            break;
        case 3:
            dprtment = "Commerce";
            break;
        case 4:
            dprtment = "Sports";
            break;
        case 5:
            dprtment = "Others";
            break;
        default:
            cout << "No department with this number, plrease try again" << endl;
            addMember();
            return;
        }
        staff.setId();
        int stafId = staff.getId();

        Member = new Staff(0, name, stafId, dprtment);
        break;
    }
    default:
        cout << "No type with this number, plrease try again" << endl;
        addMember();
        return;
    }
    Member->setId();
    int id = Member->getId();

    members.push_back(Member);
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