#include <iostream>
using namespace std;

struct node {
    int n;
    node *next;

    node (int d) {
        n = d;
        next = NULL;
    }
};

// O (n)
node *ins_end (node *head, int x) {
    if (head == NULL) {
        head = new node (x);
    }

    else {
        node *temp = head;
        while (temp -> next != NULL) {
            temp = temp -> next;    
        }

        temp -> next = new node (x);
    }

    return head;
}

// O (1), *ptr can never be the last pointer
void del_with_pointer (node *ptr) {
    node *temp = ptr -> next;
    ptr -> n = temp -> n;
    ptr -> next = temp -> next;
}


void print (node *head) {
    while (head != NULL) {
        cout << head -> n << " ";
        head = head -> next;
    }

    cout << endl;
}

int main() {
    node *head = NULL;

    head = ins_end (head, 10);
    head = ins_end (head, 20);
    head = ins_end (head, 30);
    head = ins_end (head, 40);
    head = ins_end (head, 50);
    
    print (head);
    cout << "\n";
    
    del_with_pointer (head -> next -> next); // delete 30

    print (head);
    cout << "\n";

    return 0;
}
