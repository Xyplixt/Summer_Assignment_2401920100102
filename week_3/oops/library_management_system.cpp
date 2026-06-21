#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class LibraryItem {
protected:
    int itemID;
    string title;
    string author;

public:
    virtual void input() {
        cout << "Enter Item ID: ";
        cin >> itemID;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);
    }

    virtual void display() {
        cout << "\nItem ID: " << itemID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
    }

    virtual double calculateFine(int daysLate) = 0;

    int getID() {
        return itemID;
    }

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    int pages;

public:
    void input() override {
        LibraryItem::input();

        cout << "Enter Number of Pages: ";
        cin >> pages;
    }

    void display() override {
        cout << "\n--- Book ---";
        LibraryItem::display();
        cout << "\nPages: " << pages << endl;
    }

    double calculateFine(int daysLate) override {
        return daysLate * 2.0;
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    void input() override {
        LibraryItem::input();

        cout << "Enter Issue Number: ";
        cin >> issueNumber;
    }

    void display() override {
        cout << "\n--- Magazine ---";
        LibraryItem::display();
        cout << "\nIssue Number: " << issueNumber << endl;
    }

    double calculateFine(int daysLate) override {
        return daysLate * 1.0;
    }
};

class Member {
private:
    int memberID;
    string memberName;
    int borrowedItems;

public:
    void input() {
        cout << "Enter Member ID: ";
        cin >> memberID;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, memberName);

        borrowedItems = 0;
    }

    void display() {
        cout << "\nMember ID: " << memberID;
        cout << "\nMember Name: " << memberName;
        cout << "\nBorrowed Items: " << borrowedItems << endl;
    }
};

void saveItems(vector<LibraryItem*> &items) {
    ofstream file("library.txt");

    file << items.size() << endl;

    file.close();

    cout << "\nRecords Saved Successfully!\n";
}

int main() {
    vector<LibraryItem*> items;
    vector<Member> members;

    int choice;

    do {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add Magazine\n";
        cout << "3. Display All Items\n";
        cout << "4. Register Member\n";
        cout << "5. Search Item\n";
        cout << "6. Return Item & Calculate Fine\n";
        cout << "7. Save Records\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1: {
            LibraryItem *b = new Book();
            b->input();
            items.push_back(b);
            break;
        }

        case 2: {
            LibraryItem *m = new Magazine();
            m->input();
            items.push_back(m);
            break;
        }

        case 3:
            for(auto item : items)
                item->display();
            break;

        case 4: {
            Member m;
            m.input();
            members.push_back(m);
            break;
        }

        case 5: {
            int id;
            cout << "Enter Item ID to Search: ";
            cin >> id;

            bool found = false;

            for(auto item : items) {
                if(item->getID() == id) {
                    item->display();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Item Not Found!\n";

            break;
        }

        case 6: {
            int id, days;
            cout << "Enter Item ID: ";
            cin >> id;

            cout << "Enter Late Days: ";
            cin >> days;

            bool found = false;

            for(auto item : items) {
                if(item->getID() == id) {
                    cout << "Fine = Rs. "
                         << item->calculateFine(days)
                         << endl;
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Item Not Found!\n";

            break;
        }

        case 7:
            saveItems(items);
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 8);

    for(auto item : items)
        delete item;

    return 0;
}
