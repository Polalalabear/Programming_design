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
    Node* cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void reverse(Node** head){
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* cur = *head;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void free_list(Node* head){
    while(head){    
        Node* cur = head;
        head = head->next;
        delete cur;
    }
}

void find(Node* head, int k){
    Node* cur = head;
    while(k--){
        cur = cur->next;
    }
    cout << cur->val;
}

int main(){
    Node* head = nullptr;
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        insert(&head, i);
    }
    reverse(&head);
    find(head, k-1);

    return 0;
}