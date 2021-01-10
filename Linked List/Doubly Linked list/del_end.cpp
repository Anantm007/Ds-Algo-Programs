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

// O (n)
node *ins_end (node *head, int data) {
    node *temp = new node (data);

    if (head == NULL) {
        return temp;
    }

    node *cur = head;

    while (cur -> next != NULL) {
        cur = cur -> next;
    }

    cur -> next = temp;
    temp -> prev = cur;

    return head;
}

// O (1)
node *del_head (node *head) {
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }

    node *temp = head;
    head = head -> next;
    head ->prev = NULL;

    delete temp;

    return head;
}

// O (n)
node *del_end (node *head) {
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }

    node *cur = head;
    while (cur -> next -> next != NULL) {
        cur = cur -> next;
    }

    node *temp = cur -> next;
    cur -> next = NULL;

    delete temp;

    return head;
}

void print (node *head) {
    while (head != NULL) {
        cout << head -> n << " ";
        head = head -> next;
    }
}

int main() {
    node *head = NULL;

    head = ins_end (head, 10);
    head = ins_end (head, 20);
    head = ins_end (head, 30);
    head = ins_end (head, 40);

    print (head);

    head = del_end (head);
    cout << "\n";
    print (head);

    head = ins_end (head, 50);
    head = ins_end (head, 60);
    cout << "\n";
    print (head);
    
    head = del_end (head);
    cout << "\n";
    print (head);

    return 0;
}