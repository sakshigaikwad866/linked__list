## Title
Bank Account Management Using Singly Linked List

## Problem statement 

To implement a singly linked list in C++ to maintain bank account records. Each node stores the account number, account holder name, and account balance. The program performs insertion, deletion, searching, and display operations on bank account records using dynamic memory allocation.

## Objective 

To implement a singly linked list in C++.
To store bank account details dynamically.
To perform insertion, deletion, and searching operations.
To display all bank account records.
To understand pointers and dynamic memory allocation.

## AlgorithM

1. Start and initialize "head = NULL".
2. Create a node containing the account number, account holder name, and balance.
3. Insert the new node at the beginning of the linked list.
4. Search for the required account number and delete the node by adjusting links.
5. Traverse the linked list to search for an account number.
6. Display all account records by traversing from "head" to "NULL".
7. Repeat operations according to the user's choice.
8. Stop.


## Flowchart: Linked List Operations

             +---------+
             |  START  |
             +---------+
                  |
                  v
       +---------------------+
       | Initialize head=NULL|
       +---------------------+
                  |
                  v
       /---------------------\
      / Display menu and      \
      \ enter choice          /
       \---------------------/
                  |
                  v
       +---------------------+
       | Perform Selected    |
       | Operation:          |
       | Insert / Delete /   |
       | Search / Display    |
       +---------------------+
                  |
                  v
             +---------+
             |  Exit?  |
             +---------+
              /       \
           No           Yes
            |             |
            |             v
            |        +---------+
            |        |   END   |
            |        +---------+
            |
            +----> Return to
           Display Menu
           
## Code

#include <iostream>
using namespace std;

struct Node {
    int acc;
    string name;
    float bal;
    Node *next;
};

Node *head = NULL;

void insert() {
    Node *p = new Node;
    cin >> p->acc >> p->name >> p->bal;
    p->next = head;
    head = p;
}

void deleteAcc() {
    int x;
    cin >> x;
    Node *p = head, *q = NULL;

    while (p && p->acc != x) {
        q = p;
        p = p->next;
    }

    if (!p) return;
    if (q) q->next = p->next;
    else head = p->next;
    delete p;
}

void search() {
    int x;
    cin >> x;
    Node *p = head;

    while (p) {
        if (p->acc == x) {
            cout << p->acc << " " << p->name
                 << " " << p->bal << endl;
            return;
        }
        p = p->next;
    }
    cout << "Not Found";
}

void display() {
    Node *p = head;
    while (p) {
        cout << p->acc << " " << p->name
             << " " << p->bal << endl;
        p = p->next;
    }
}

int main() {
    int ch;

    do {
        cout << "\n1.Insert  2.Delete  3.Search  4.Display  5.Exit\n";
        cin >> ch;

        if (ch == 1) insert();
        else if (ch == 2) deleteAcc();
        else if (ch == 3) search();
        else if (ch == 4) display();

    } while (ch != 5);

    return 0;
}

## Output

1.Insert  2.Delete  3.Search  4.Display  5.Exit
1
101 Gaurav 5000

1.Insert  2.Delete  3.Search  4.Display  5.Exit
1
102 Rahul 7000

1.Insert  2.Delete  3.Search  4.Display  5.Exit
4
102 Rahul 7000
101 Gaurav 5000

1.Insert  2.Delete  3.Search  4.Display  5.Exit
3
101
101 Gaurav 5000

1.Insert  2.Delete  3.Search  4.Display  5.Exit
2
102

1.Insert  2.Delete  3.Search  4.Display  5.Exit
4
101 Gaurav 5000

1.Insert  2.Delete  3.Search  4.Display  5.Exit
5
