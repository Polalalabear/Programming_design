#include <iostream>
using namespace std;

typedef struct Node{
    int val;
    Node* next;
}Node;

void insert(Node** head, int n){
    Node* node = new Node();
    node->val = n;
    node->next = nullptr;
    if(!(*head))   *head = node;
    else{
        Node* cur = *head;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = node;
    }
}

void show(Node* head){
    if(head != nullptr){
        show(head->next);
        cout << head->val << ((head && head->val != 1) ? "->" : "");
    }
}

void free_list(Node* head){
    while(head){    
        Node* cur = head;
        head = head->next;
        delete cur;
    }
}

int main(){
    Node* head = nullptr;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        insert(&head, i);
    }
    show(head);
    free_list(head);
    return 0;
}