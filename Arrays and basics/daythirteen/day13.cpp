#include <bits/stdc++.h>
using namespace std; 

struct Node{
    int val ;
    Node* next;
    Node(int data ){
        val = data;
        next = NULL;
    }
};

Node* detectCycle(Node* head){
    unordered_map<Node* , bool>visited;
    while(head!=NULL){
        if(visited.find(head)!=visited.end()){
            return head;
        }
    visited[head] = true;  
    head = head->next;      
    }
    return NULL;
}

int main(){
    Node* head = new Node(6);
    head ->next = new Node(2);
    head ->next ->next = new Node(4);
    head->next->next->next = head->next;
    Node* solution = detectCycle(head);

    if(detectCycle){
        cout << "cycle is at node with value: "  << solution->val;
    }else{
        cout<<" NO!! ";
    }


}