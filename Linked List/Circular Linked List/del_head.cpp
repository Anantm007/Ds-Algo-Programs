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
node *del_head (node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head -> next == head) {
        delete head;
        return NULL;
    }

    node *cur = head;
    do {
        cur = cur -> next;
    } while (cur -> next != head);

    cur -> next = head -> next;
    delete head;

    return cur -> next;
}

// O (1)
node *del_head_const_time (node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head -> next == head) {
        delete head;
        return NULL;
    }

    head -> n = head -> next -> n;
    node *temp = head -> next;

    head -> next = head -> next -> next;

    delete temp;

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

    head = ins_end_const_time (head, 50);
    head = ins_end_const_time (head, 60);
    head = ins_end_const_time (head, 70);
    print (head);
    cout << "\n";

    head = del_head_const_time (head);
    print (head);
    cout << "\n";

    head = del_head_const_time (head);
    print (head);
    cout << "\n";

    head = del_head_const_time (head);
    print (head);
    cout << "\n";

    return 0;
}