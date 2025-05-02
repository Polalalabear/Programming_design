#include <iostream>
#include <algorithm>
#include <vector>
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

void delete_dup(Node** head){
    Node* cur = *head;
    while(cur && cur->next){
        if(cur->val == cur->next->val){
            Node* dup = cur->next;
            cur->next = dup->next;
            delete dup;
        }
        cur = cur->next;
    }
}

void sort_list_show(Node* head){
    Node* cur = head;
    vector<int> arr;
    while(cur){
        arr.push_back(cur->val);
        cur = cur->next;
    }
    sort(arr.begin(), arr.end());
    for(auto i:  arr)    cout << i << " ";
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
    while(cin >> n){
        insert(&head, n);
    }
    delete_dup(&head);
    sort_list_show(head);
    free_list(head);
    return 0;
}