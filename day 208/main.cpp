#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr){}
};

Node *partition(Node *head, int k){
    Node less_dumpy(0);
    Node greater_dumpy(0);

    Node* less = &less_dumpy;
    Node* greater = &greater_dumpy;

    Node* current = head;

    while(current){
        if(current->val < k){
            less->next = current;
            less = less->next;
        } else{
            greater->next = current;
            greater = greater->next;
        }
        current = current->next;
    }

    //ket hop 2 danh sanh
    less->next = greater_dumpy.next;
    greater->next = nullptr;

    return less_dumpy.next;
}

void printList(Node *head){
    cout << head->val;
    head = head->next;
    while(head){
        cout <<" -> " << head->val;
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Tạo danh sách liên kết 5 -> 1 -> 8 -> 0 -> 3
    Node* head = new Node(5);
    head->next = new Node(1);
    head->next->next = new Node(8);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(3);

    int k = 3;
    Node* new_head = partition(head, k);

    // In danh sách đã phân chia
    printList(new_head);
    
    return 0;
}