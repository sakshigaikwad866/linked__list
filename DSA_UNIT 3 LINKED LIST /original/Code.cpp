#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int acc;
    string name;
    float bal;
    Node *next;
};

Node *head = NULL;

void insert() 
{
    Node *p = new Node;

    cout << "Enter Account Number, Name and Balance: ";
    cin >> p->acc >> p->name >> p->bal;

    p->next = head;
    head = p;

    cout << "Account Inserted Successfully\n";
}

void deleteAcc() 
{
    int x;
    cout << "Enter Account Number to Delete: ";
    cin >> x;

    Node *p = head, *q = NULL;

    while (p != NULL && p->acc != x)
        {
        q = p;
        p = p->next;
    }

    if (p == NULL) 
    {
        cout << "Account Not Found\n";
        return;
    }

    if (q != NULL)
        q->next = p->next;
    else
        head = p->next;

    delete p;
    cout << "Account Deleted Successfully\n";
}

void search() 
{
    int x;
    cout << "Enter Account Number to Search: ";
    cin >> x;

    Node *p = head;

    while (p != NULL)
        {
        if (p->acc == x) 
        {
            cout << "Account Number: " << p->acc
                 << "\nName: " << p->name
                 << "\nBalance: " << p->bal << endl;
            return;
        }
        p = p->next;
    }

    cout << "Not Found\n";
}

void display() 
{
    Node *p = head;

    if (p == NULL)
    {
        cout << "No Accounts Available\n";
        return;
    }

    while (p != NULL) 
    {
        cout << "Account Number: " << p->acc
             << " Name: " << p->name
             << " Balance: " << p->bal << endl;

        p = p->next;
    }
}

int main() 
{
    int ch;

    do {
        cout << "\n1. Insert  2. Delete  3. Search";
        cout << "\n4. Display  5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        if (ch == 1)
            insert();
        else if (ch == 2)
            deleteAcc();
        else if (ch == 3)
            search();
        else if (ch == 4)
            display();
        else if (ch == 5)
            cout << "Exiting Program\n";
        else
            cout << "Invalid Choice\n";

    } while (ch != 5);

    return 0;
}
