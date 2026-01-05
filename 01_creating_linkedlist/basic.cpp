//Singly Linked List

#include<iostream>
using namespace std;

class Node{
    //creating node structure
    public:
           int DataPart;
           Node* LinkPart;
           //constructor
           Node(int info)
           {
            DataPart = info;
            LinkPart = NULL;
           }
};

int main()
{
    //creating nodes
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);

    //linking nodes
    node1->LinkPart = node2;
    node2->LinkPart = node3;
    node3->LinkPart = NULL;

    Node* start = node1;
    
    //printing linkedlist (traversed)
    for (Node* temp = start; temp != NULL; temp = temp->LinkPart)
    {
        cout << temp->DataPart <<" "<<endl;
    }
    
    return 0;
}