
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;  
    Node* next; 
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node *findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2 + 1;
    temp = head;
    while (temp != nullptr) {
        mid = mid - 1;
        if (mid == 0){
           
            break;
        }
        temp = temp->next;
    }
    return temp;
}

int main() {
    // Creating a sample linked list: 
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find the middle node
    Node* middleNode = findMiddle(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->data << endl;

    return 0;
}
                                