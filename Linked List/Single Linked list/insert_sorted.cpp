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
node *ins_sorted (node *head, int x) {
    node *temp = new node (x);

    if (head == NULL) {
        return temp;
    }

    if (x < head -> n) {
        temp -> next = head;
        return temp;
    }

    node *cur = head;

    while (cur -> next != NULL && cur -> next -> n < x) {
        cur = cur -> next;
    }

    temp -> next = cur -> next;
    cur -> next = temp;

    return head;
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

    head = ins_sorted (head, 20);
    head = ins_sorted (head, 40);
    head = ins_sorted (head, 30);
    head = ins_sorted (head, 10);
    head = ins_sorted (head, 30);

    print (head);
    cout << "\n";

    return 0;
}
