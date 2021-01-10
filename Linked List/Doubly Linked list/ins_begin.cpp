#include <iostream>
using namespace std;

struct node {
    int n;
    node *next;
    node *prev;

    node (int d) {
        n = d;
        next = NULL;
        prev = NULL;
    }
};

// O (1)
node *ins_begin (node *head, int data) {
    node *temp = new node (data);
    temp -> next = head;

    if (head != NULL) {
        head -> prev = temp;
    }

    return temp;
}

void print (node *head) {
    while (head != NULL) {
        cout << head -> n << " ";
        head = head -> next;
    }
}

int main() {
    node *head = NULL;

    head = ins_begin (head, 10);
    head = ins_begin (head, 20);
    head = ins_begin (head, 30);
    head = ins_begin (head, 40);

    print (head);

    return 0;
}
