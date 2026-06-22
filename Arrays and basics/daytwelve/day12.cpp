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
//reverse the ll in group of k

Node* reversegrp(Node* arr , int k ){
    Node* temp = arr;
    int cnt =0;
    while(cnt <k){
        if(temp == NULL){
            return arr;
        }
        temp = temp ->next;
        cnt++;
    }
    Node* prevNode = reversegrp(temp , k);

    temp = arr ;
    cnt =0;

    while(cnt<k){
        Node* next = temp ->next;
        temp ->next = prevNode;
        prevNode = temp ;
        temp = next ;
        cnt++;
    }
    return prevNode;
}
//how to delete any node;

void deleteNode(Node* node){
    node->val = node->next->val;
    node->next = node->next ->next;

}
//detect cycle
bool circledetect(Node* arr){
    //brute force 

    // Node* temp = arr;
    // unordered_map<Node* , int>mp;
    // while(temp!=NULL){
    //     if(mp.find(temp)!=mp.end()){
    //         return true;
    //     }
    //     temp = temp->next;
    // }
    // return false;

    //optimal 
    if(arr==NULL || arr->next==NULL){
        return false;
    }
    Node* fast = arr;
    Node* slow = arr;
    while(fast != NULL && fast ->next!=NULL){
        fast = fast ->next->next;
        slow = slow->next;
        if(slow == fast ){
            return true;
        }
    }
    return false;
}
int main (){
    Node* arr = new Node(7);
    arr->next = new Node(8);
    arr->next->next = new Node(2);
    arr->next ->next->next = new Node(4);
    arr ->next->next ->next ->next =new Node(6);

    deleteNode(arr->next->next);
    Node* curr = arr;
    while(curr!=NULL){
        cout << curr->val<<" "; 
        curr = curr->next;
    }
    cout << endl;
    
    Node* reversebyk = reversegrp(arr, 2);
    Node* temp = reversebyk;
    while(temp!=NULL){
        cout << temp ->val << " ";
        temp = temp ->next;
    }
    // if(circledetect(arr)){
    //     cout<< "circle detected " ;

    // }else{
    //     cout << "NO circle is detected";
    // }

}