#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pre;
    Node* next;

    Node(int info) {
        data = info;
        pre = nullptr;
        next = nullptr;
    }
};

// create doubly linked list 
void createList(Node*& start, int info) {
    start = new Node(info);
    cout << "doubly linked list created\n";
}

// display forward using for loop 
void displayForward(Node* start) {
    if (start == nullptr) {
        cout << "list is empty\n";
        return;
    }

    cout << "forward: ";
    for (Node* temp = start; temp != nullptr; temp = temp->next)
        cout << temp->data << " <-> ";

    cout << "null\n";
}

// display backward using for loop 
void displayBackward(Node* start) {
    if (start == nullptr) {
        cout << "list is empty\n";
        return;
    }

    Node* tail;
    for (tail = start; tail->next != nullptr; tail = tail->next)
        ;

    cout << "backward: ";
    for (; tail != nullptr; tail = tail->pre)
        cout << tail->data << " <-> ";

    cout << "null\n";
}

// count nodes 
int countNodes(Node* start) {
    int count = 0;
    for (Node* temp = start; temp != nullptr; temp = temp->next)
        count++;
    return count;
}

// insert at beginning 
void insertAtBeginning(Node*& start, int info) {
    Node* newNode = new Node(info);

    if (start != nullptr) {
        newNode->next = start;
        start->pre = newNode;
    }

    start = newNode;
}

// insert at end 
void insertAtEnd(Node*& start, int info) {
    Node* newNode = new Node(info);

    if (start == nullptr) {
        start = newNode;
        return;
    }

    Node* temp;
    for (temp = start; temp->next != nullptr; temp = temp->next)
        ;

    temp->next = newNode;
    newNode->pre = temp;
}

// insert at specific position (1-based) 
void insertAtPosition(Node*& start, int info, int position) {
    int n = countNodes(start);

    if (position < 1 || position > n + 1) {
        cout << "invalid position\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(start, info);
        return;
    }

    Node* temp = start;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;

    Node* newNode = new Node(info);
    newNode->next = temp->next;
    newNode->pre = temp;

    if (temp->next != nullptr)
        temp->next->pre = newNode;

    temp->next = newNode;
}

// delete from beginning 
void deleteFromBeginning(Node*& start) {
    if (start == nullptr) {
        cout << "list is empty\n";
        return;
    }

    Node* temp = start;
    start = start->next;

    if (start != nullptr)
        start->pre = nullptr;

    delete temp;
}

// delete from end 
void deleteFromEnd(Node*& start) {
    if (start == nullptr) {
        cout << "list is empty\n";
        return;
    }

    if (start->next == nullptr) {
        delete start;
        start = nullptr;
        return;
    }

    Node* temp;
    for (temp = start; temp->next != nullptr; temp = temp->next)
        ;

    temp->pre->next = nullptr;
    delete temp;
}

// delete at specific position 
void deleteAtPosition(Node*& start, int position) {
    int n = countNodes(start);

    if (position < 1 || position > n) {
        cout << "invalid position\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning(start);
        return;
    }

    Node* temp = start;
    for (int i = 1; i < position; i++)
        temp = temp->next;

    temp->pre->next = temp->next;

    if (temp->next != nullptr)
        temp->next->pre = temp->pre;

    delete temp;
}

// reverse doubly linked list 
void reverseList(Node*& start) {
    Node* temp = nullptr;

    for (Node* current = start; current != nullptr; current = current->pre) {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
    }

    if (temp != nullptr)
        start = temp->pre;
}

// main menu 
int main() {
    Node* start = nullptr;
    int choice, info, pos;

    for (;;) {
        cout << "\n===== doubly linked list menu =====\n";
        cout << "1. create list\n";
        cout << "2. display forward\n";
        cout << "3. display backward\n";
        cout << "4. insert at beginning\n";
        cout << "5. insert at end\n";
        cout << "6. insert at position\n";
        cout << "7. delete from beginning\n";
        cout << "8. delete from end\n";
        cout << "9. delete at position\n";
        cout << "10. reverse list\n";
        cout << "0. exit\n";
        cout << "enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cin >> info;
                createList(start, info);
                break;

            case 2:
                displayForward(start);
                break;

            case 3:
                displayBackward(start);
                break;

            case 4:
                cin >> info;
                insertAtBeginning(start, info);
                break;

            case 5:
                cin >> info;
                insertAtEnd(start, info);
                break;

            case 6:
                cin >> info >> pos;
                insertAtPosition(start, info, pos);
                break;

            case 7:
                deleteFromBeginning(start);
                break;

            case 8:
                deleteFromEnd(start);
                break;

            case 9:
                cin >> pos;
                deleteAtPosition(start, pos);
                break;

            case 10:
                reverseList(start);
                cout << "list reversed\n";
                break;

            case 0:
                return 0;

            default:
                cout << "invalid choice\n";
        }
    }
}
