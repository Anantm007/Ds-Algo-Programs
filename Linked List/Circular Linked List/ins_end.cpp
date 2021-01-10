#include <bits/stdc++.h>

using namespace std;

// node Structure
struct node {
    int n;
    node *next;

    node (int data) {
        n = data;
        next = NULL;
    }
};

// O (n)
node *ins_end (node *head, int d) {
    node *temp = new node (d);

    if (head == NULL) {
        temp -> next = temp;

        return temp;
    }

    node *cur = head;

    do {
        cur = cur -> next;
    } while (cur -> next != head);

    cur -> next = temp;
    temp -> next = head;

    return head;
}

// O (1) 
node *ins_end_const_time (node *head, int d) {
    node *temp = new node (d);

    if (head == NULL) {
        temp -> next = temp;

        return temp;
    }

    temp -> next = head -> next;
    head -> next = temp;

    // Swap first and second
    int x;
    x = head -> n;
    head -> n = temp -> n;
    temp -> n = x;
    
    return temp;
}

void print (node *head) {
    if (head == NULL) {
        return;
    }

    node *p = head;

    do {
        cout << p -> n << " ";
        p = p -> next;
    } while (p != head);
}

int main () {
    node *head = NULL;

    head = ins_end (head, 10);
    head = ins_end (head, 20);
    head = ins_end (head, 30);
    head = ins_end (head, 40);

    print (head);
    cout << "\n";


    head = ins_end_const_time (head, 50);
    head = ins_end_const_time (head, 60);
    head = ins_end_const_time (head, 70);
    head = ins_end_const_time (head, 80);

    print (head);
    cout << "\n";
    
    return 0;
}