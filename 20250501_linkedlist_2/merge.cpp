#include <iostream>
#include <vector>
#include <algorithm>
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

Node* merge_list(Node* head1, Node* head2){
    Node* cur1 = head1;
    Node* cur2 = head2;
    Node* combine = nullptr;
    vector<int> arr;
    while(cur1){
        arr.push_back(cur1->val);
        cur1 = cur1->next;
    }
    while(cur2){
        arr.push_back(cur2->val);
        cur2 = cur2->next;
    }    

    sort(arr.begin(), arr.end());
    for(auto i: arr)    insert(&combine, i);
    return combine;
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
    string line1, line2;
    cin >> n;
    cin.ignore();

    while(n--){
        Node* head1 = nullptr;
        Node* head2 = nullptr;
        getline(cin, line1);
        if (line1.empty()){
            n++;
            continue;
        }
        istringstream s(line1);

        long long int num1;
        while (s >> num1)    insert(&head1, num1);

        getline(cin, line2);
        if(line2.empty()){
            n++;
            continue;
        }
        istringstream s2(line2);
        long long int num2;
        while(s2 >> num2)     insert(&head2, num2);

        Node* combine = merge_list(head1, head2);
        show(combine);

        free_list(head1);
        free_list(head2);
    }

    return 0;
}