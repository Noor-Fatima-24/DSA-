#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    //contructor
    Node(int info) {
        data = info;
        link = nullptr;
    }
};

// create a new linked list with one node 
void createLinkedList(Node*& start, int value) {
    start = new Node(value);
    cout << "linked list created with first node: " << value << endl;
}

// display the linked list 
void display(Node* start) {
    if (start == nullptr) {
        cout << "list is empty.\n";
        return;
    }

    Node* current = start;
    cout << "linked list: ";

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->link;
    }

    cout << "null\n";
}

// count number of nodes 
int countNodes(Node* start) {
    int count = 0;

    for (Node* current = start; current != nullptr; current = current->link)
        count++;

    return count;
}

// insert at beginning 
void insertAtBeginning(Node*& start, int value) {
    Node* newNode = new Node(value);
    newNode->link = start;
    start = newNode;
}

// insert at end 
void insertAtEnd(Node*& start, int value) {
    Node* newNode = new Node(value);

    if (start == nullptr) {
        start = newNode;
        return;
    }

    Node* current = start;
    while (current->link != nullptr)
        current = current->link;

    current->link = newNode;
}

// insert at specific position (1-based) 
void insertAtPosition(Node*& start, int value, int position) {
    int n = countNodes(start);

    if (position < 1 || position > n + 1) {
        cout << "invalid position! list has " << n << " nodes.\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(start, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = start;

    for (int i = 1; i < position - 1; i++)
        current = current->link;

    newNode->link = current->link;
    current->link = newNode;
}

// insert after a given value 
void insertAfterValue(Node* start, int value, int afterValue) {
    Node* current;

    for (current = start;
         current != nullptr && current->data != afterValue;
         current = current->link)
        ;

    if (current == nullptr) {
        cout << "value not found!\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->link = current->link;
    current->link = newNode;
}

// insert before a given value 
void insertBeforeValue(Node*& start, int value, int beforeValue) {
    if (start == nullptr) {
        cout << "list is empty!\n";
        return;
    }

    if (start->data == beforeValue) {
        insertAtBeginning(start, value);
        return;
    }

    Node* current;

    for (current = start;
         current->link != nullptr && current->link->data != beforeValue;
         current = current->link)
        ;

    if (current->link == nullptr) {
        cout << "value not found!\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->link = current->link;
    current->link = newNode;
}

// delete from beginning 
void deleteFromBeginning(Node*& start) {
    if (start == nullptr) {
        cout << "list is empty!\n";
        return;
    }

    Node* temp = start;
    start = start->link;
    delete temp;
}

// delete from end 
void deleteFromEnd(Node*& start) {
    if (start == nullptr) {
        cout << "list is empty!\n";
        return;
    }

    if (start->link == nullptr) {
        delete start;
        start = nullptr;
        return;
    }

    Node* current;
    for (current = start; current->link->link != nullptr; current = current->link)
        ;

    delete current->link;
    current->link = nullptr;
}

// delete at specific position 
void deleteAtPosition(Node*& start, int position) {
    int n = countNodes(start);

    if (position < 1 || position > n) {
        cout << "invalid position!\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning(start);
        return;
    }

    Node* current = start;
    for (int i = 1; i < position - 1; i++)
        current = current->link;

    Node* temp = current->link;
    current->link = temp->link;
    delete temp;
}

// delete by value 
void deleteByValue(Node*& start, int value) {
    if (start == nullptr) {
        cout << "list is empty!\n";
        return;
    }

    if (start->data == value) {
        deleteFromBeginning(start);
        return;
    }

    Node* current;
    for (current = start;
         current->link != nullptr && current->link->data != value;
         current = current->link)
        ;

    if (current->link == nullptr) {
        cout << "value not found!\n";
        return;
    }

    Node* temp = current->link;
    current->link = temp->link;
    delete temp;
}

// search an element 
bool searchElement(Node* start, int value) {
    for (Node* current = start; current != nullptr; current = current->link) {
        if (current->data == value)
            return true;
    }
    return false;
}

// reverse the linked list 
void reverseList(Node*& start) {
    Node* prev = nullptr;
    Node* current = start;
    Node* nextNode;

    for (; current != nullptr; ) {
        nextNode = current->link;
        current->link = prev;
        prev = current;
        current = nextNode;
    }

    start = prev;
}

// remove duplicate nodes (sorted list) 
void removeDuplicates(Node* start) {
    if (start == nullptr)
        return;

    Node* current = start;

    for (; current->link != nullptr; ) {
        if (current->data == current->link->data) {
            Node* temp = current->link;
            current->link = temp->link;
            delete temp;
        } else {
            current = current->link;
        }
    }
}

// main menu 
int main() {
    Node* head = nullptr;
    int choice, value, pos, afterVal, beforeVal;

    for (;;) {
        cout << "\n===== linked list menu =====\n";
        cout << "1. create linked list\n";
        cout << "2. display linked list\n";
        cout << "3. count nodes\n";
        cout << "4. insert at beginning\n";
        cout << "5. insert at end\n";
        cout << "6. insert at position\n";
        cout << "7. insert after value\n";
        cout << "8. insert before value\n";
        cout << "9. delete from beginning\n";
        cout << "10. delete from end\n";
        cout << "11. delete at position\n";
        cout << "12. delete by value\n";
        cout << "13. search element\n";
        cout << "14. reverse linked list\n";
        cout << "15. remove duplicates\n";
        cout << "0. exit\n";
        cout << "enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "enter value: ";
                cin >> value;
                createLinkedList(head, value);
                break;

            case 2:
                display(head);
                break;

            case 3:
                cout << "number of nodes: " << countNodes(head) << endl;
                break;

            case 4:
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 5:
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 6:
                cin >> value >> pos;
                insertAtPosition(head, value, pos);
                break;

            case 7:
                cin >> value >> afterVal;
                insertAfterValue(head, value, afterVal);
                break;

            case 8:
                cin >> value >> beforeVal;
                insertBeforeValue(head, value, beforeVal);
                break;

            case 9:
                deleteFromBeginning(head);
                break;

            case 10:
                deleteFromEnd(head);
                break;

            case 11:
                cin >> pos;
                deleteAtPosition(head, pos);
                break;

            case 12:
                cin >> value;
                deleteByValue(head, value);
                break;

            case 13:
                cin >> value;
                cout << (searchElement(head, value) ? "value found\n" : "value not found\n");
                break;

            case 14:
                reverseList(head);
                cout << "linked list reversed\n";
                break;

            case 15:
                removeDuplicates(head);
                cout << "duplicates removed\n";
                break;

            case 0:
                return 0;

            default:
                cout << "invalid choice!\n";
        }
    }
}
