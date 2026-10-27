#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int accNo;
    string name;
    float balance;
    Node* next;
};

Node* top = NULL;
Node* front = NULL;
Node* rear = NULL;

// Insert account into Stack
void push()
{
    Node* newNode = new Node;

    cout << "Enter Account Number: ";
    cin >> newNode->accNo;

    cout << "Enter Account Holder Name: ";
    cin >> newNode->name;

    cout << "Enter Balance: ";
    cin >> newNode->balance;

    newNode->next = top;
    top = newNode;

    cout << "Account added to Stack successfully!\n";
}

// Delete account from Stack
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = top;
    cout << "Deleted Account Number: " << temp->accNo << endl;

    top = top->next;
    delete temp;
}

// Display Stack
void displayStack()
{
    if (top == NULL)
    {
        cout << "Stack is empty!\n";
        return;
    }

    Node* temp = top;

    cout << "\nAccounts in Stack:\n";

    while (temp != NULL)
    {
        cout << "Account Number: " << temp->accNo
             << ", Name: " << temp->name
             << ", Balance: " << temp->balance << endl;

        temp = temp->next;
    }
}

// Insert account into Queue
void enqueue()
{
    Node* newNode = new Node;

    cout << "Enter Account Number: ";
    cin >> newNode->accNo;

    cout << "Enter Account Holder Name: ";
    cin >> newNode->name;

    cout << "Enter Balance: ";
    cin >> newNode->balance;

    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Account added to Queue successfully!\n";
}

// Delete account from Queue
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = front;

    cout << "Deleted Account Number: " << temp->accNo << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

// Display Queue
void displayQueue()
{
    if (front == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = front;

    cout << "\nAccounts in Queue:\n";

    while (temp != NULL)
    {
        cout << "Account Number: " << temp->accNo
             << ", Name: " << temp->name
             << ", Balance: " << temp->balance << endl;

        temp = temp->next;
    }
}

// Search account in Stack and Queue
void searchAccount()
{
    int number;
    cout << "Enter Account Number to Search: ";
    cin >> number;

    Node* temp = top;

    while (temp != NULL)
    {
        if (temp->accNo == number)
        {
            cout << "Account Found in Stack!\n";
            cout << "Name: " << temp->name
                 << ", Balance: " << temp->balance << endl;
            return;
        }
        temp = temp->next;
    }

    temp = front;

    while (temp != NULL)
    {
        if (temp->accNo == number)
        {
            cout << "Account Found in Queue!\n";
            cout << "Name: " << temp->name
                 << ", Balance: " << temp->balance << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Account Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK ACCOUNT MANAGEMENT =====\n";
        cout << "1. Insert Account into Stack\n";
        cout << "2. Delete Account from Stack\n";
        cout << "3. Display Stack\n";
        cout << "4. Insert Account into Queue\n";
        cout << "5. Delete Account from Queue\n";
        cout << "6. Display Queue\n";
        cout << "7. Search Account\n";
        cout << "8. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                enqueue();
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                searchAccount();
                break;

            case 8:
                cout << "Program Terminated.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    while (top != NULL)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    while (front != NULL)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}

