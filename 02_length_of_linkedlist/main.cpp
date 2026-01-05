#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;

    Node(int info) {
        data = info;
        link = nullptr;
    }
};

// Standalone counting function
int counting(Node* start) {
    int counter = 0;
    for (Node* current = start; current != nullptr; current = current->link) {
        counter++;
    }
    return counter;
}

int main() {
    Node* start = new Node(10);
    start->link = new Node(20);
    start->link->link = new Node(30);

    cout << "Number of nodes: " << counting(start) << endl; // Output: 3
    return 0;
}
