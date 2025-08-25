#include<iostream>
#include<vector>
using namespace std;

class item // The Base Class
{
private:
    int id = 100;
    string title;
    string author;
    int year; // year was published
    int totalCopies; // affected only by buying new copies (by the library) (for one item)
    int availableCopies; // affteced by borrow (for one item)

public:
    void checkout();
    void checkin();

    // setters and getters functions

    void setId(){
        static int nextId = 100;
        id = ++nextId;
    }

    int getId(){
        return id;
    }

    void setTitle(){
        cin >> title;
    }

    string getTitle(){
        return title;
    }

    void setAuthor(){
        cin >> author;
    }

    string getAuthor(){
        return author;
    }

    void setYear(){
        cin >> year;
    }

    int getYear(){
        return year;
    }

    void setTotalCopies(){
        cin >> totalCopies;
    }

    int getTotalCopies(){
        return totalCopies;
    }

    void setAvailableCopies(){
        cin >> availableCopies;
    }

    int getAvailableCopies(){
        return availableCopies;
    }
};