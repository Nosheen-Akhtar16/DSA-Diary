#include <bits/stdc++.h>
using namespace std; 
class Node{
public:
    int val;
    Node* next;

    Node(int data1){
        val = data1;
        next = NULL;
    }
};

// now we will merge two sorted list 
Node* mergetwoSortedList(Node* list1, Node* list2){
    Node* list = new Node(-1);
    Node* temp = list;
    while(list1 !=NULL && list2 != NULL){
        if(list1->val >= list2->val){
            temp->next = list2;
            list2 = list2->next;
        }else{
            temp->next = list1;
            list1= list1->next;
        }
        temp = temp ->next;
    }
   if(list1!=NULL){
        temp->next = list1;
    }
    if(list2!=NULL){
        temp->next = list2;
    }
    return list->next;
}

void printlist(Node* head){
     Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->val << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main(){
    Node* list1 = new Node(2);
    list1-> next = new Node(3);
    list1 -> next -> next = new Node(5);
    list1 ->next->next->next = new Node(7);
    
    Node* list2 = new Node(4);
    list2 ->next = new Node(6);
    list2->next->next = new Node(8);

    cout<< " our first list is : " ;
    printlist(list1);
    cout<< endl;
    cout<< " Our second list is: ";
    printlist(list2);
    Node* mergelist = mergetwoSortedList(list1 , list2);
    cout << "merged sorted list: ";
    printlist(mergelist);
    cout<< endl;

}