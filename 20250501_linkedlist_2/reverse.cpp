#include <iostream>
#include <sstream>
#include <string>
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

int main(){
    int n;
    string line;
    cin >> n;
    cin.ignore();

    while(n--){
        Node* head = nullptr;
        getline(cin, line);
        if (line.empty()){
            n++;
            continue;
        }

        istringstream s(line);
        long long int num;
        while (s >> num){
            insert(&head, num);
        }
        reverse(&head);
        show(head);
        free_list(head);
    }

    return 0;
}