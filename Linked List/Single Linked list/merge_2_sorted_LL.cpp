#include <bits/stdc++.h>
using namespace std;

struct node {
    int n;
    node *next;

    node (int data) {
        n = data;
        next = NULL;
    }
};

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

node *merge_2_sorted (node *head1, node *head2) {
    return NULL;
}

void print (node *head) {
    if (head == NULL) {
        return;
    }

    while (head != NULL) {
        cout << head -> n << " ";
        head =  head -> next;
    }
}
int main () {
    node *head1 = NULL, *head2 = NULL;

    // List 1 
    head1 = ins_end (head1, 10);
    head1 = ins_end (head1, 22);
    head1 = ins_end (head1, 39);
    head1 = ins_end (head1, 46);
    head1 = ins_end (head1, 58);
    head1 = ins_end (head1, 400);
    print (head1);
    cout << "\n";

    // List 2
    head2 = ins_end (head2, 0);
    head2 = ins_end (head2, 23);
    head2 = ins_end (head2, 340);
    head2 = ins_end (head2, 400);
    head2 = ins_end (head2, 587);
    print (head2);
    cout << "\n";

    // Sorted list
    node *head = merge_2_sorted (head1, head2);
    print (head);
    cout << "\n";

    return 0;
}