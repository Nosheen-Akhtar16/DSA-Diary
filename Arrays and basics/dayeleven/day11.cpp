
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }

};
//that is brute force
// find nth elemnt from back of linked list 

// Node* deleteNthEle(Node* head, int N){
//     Node* temp = head;
//     int count=0;
//     while(temp!=NULL){
//         count++;
//         temp = temp->next;
//     }

//     if(count == N){
//         Node* newhead = head->next;
//         free(head);
//         return newhead;
//     }
//     int res = count - N;
//     temp = head;
//     while(temp!=NULL){
//         res--;
//         if(res==0){
//             break;
//         }
//         temp = temp->next;
       
//     }
//     Node* deleteNode = temp ->next;
//     temp ->next = temp->next->next;
//         free(deleteNode);

//     return head;
// }


//for more optimal approach 
Node* deleteNthEle(Node*head , int N){
    Node* fast = head;
    for(int i=0; i<N; i++){
        fast = fast ->next;
    }
     if(fast == NULL){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* slow = head;
    while(fast->next !=NULL){
        slow = slow->next ;
        fast = fast ->next ;

    }
    Node* delNode = slow->next;
    slow->next = slow->next ->next;
    delete delNode;
    return head;
}
//now we  will see how to add 2 number in linked list 
Node* addToList(Node* head , Node* list){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    int carry = 0;
    while(head!=NULL || list !=NULL ||carry){
        int sum=0;
        if(head!=NULL){
            sum += head->val;
            head = head ->next;
        }
        if(list!=NULL){
            sum+=list->val;
            list = list->next;
        }

        sum+=carry;
        carry = sum/10;
        Node* newNode = new Node(sum/10);
        temp->next = newNode;
        temp = temp->next ;

    }
    return dummyNode->next;
}
int main(){
    Node* head = new Node(8);
    head -> next = new Node(7);
    head->next ->next = new Node(13);
    head->next ->next ->next = new Node(4);
    head->next ->next ->next ->next = new Node(10);

    Node* list = new Node(8);
    list ->next = new Node(2);
    list ->next ->next = new Node(7);
cout << "added two lists: ";
    Node* ans = addToList(head, list);
    Node* demo = ans;
    while(demo!=NULL){
        cout << demo->val << " ";
        demo = demo ->next;
    }
cout << endl;
Node* head2 = deleteNthEle(head, 4);
Node* temp = head2;
cout << " list after deleting nth node: ";
while(temp != NULL){
    cout << temp->val << " ";
    temp = temp->next;
}
}