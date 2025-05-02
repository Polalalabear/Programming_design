#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
    char val;
    Node* next;
    Node* prev;
} Node;

void insert(Node** head, char c){
    Node* node = new Node();
    node->val = c;
    node->next = nullptr;
    node->prev = nullptr;

    if (!(*head))   *head = node;
    else{
        Node* cur = *head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
        node->prev = cur;
    }
}

void show(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}

bool isP(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    Node* cur = head;
    while (cur != tail && cur->prev != tail) {
        if (cur->val != tail->val)  return false;
        cur = cur->next;
        tail = tail->prev;
    }
    return true;
}

void free_list(Node* head){
    while (head){
        Node* cur = head;
        head = head->next;
        delete cur;
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while (n--){
        Node* head = nullptr;
        string s;
        getline(cin, s);
        for (char c : s){
            if (c != ' ')   insert(&head, c);
        }
        if (isP(head))  cout << "Yes\n";
        else    cout << "No\n";

        free_list(head);
    }
    return 0;
}
