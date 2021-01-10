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
node *reverse (node *head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    node *cur = head, *prev = NULL;

    while (cur != NULL) {
        // Swapping
        prev = cur -> prev;
        cur -> prev = cur -> next;
        cur -> next = prev; 

        cur = cur -> prev;
    }

    head = prev -> prev;
    
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

    head = reverse (head);
    
    cout << "\n";
    print (head);

    return 0;
}