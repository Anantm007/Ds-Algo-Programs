#include <iostream>
using namespace std;

// node Structure
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

// O (1)
node *delete_head (node *head) {
    if (head == NULL) {
        return NULL;
    }

    node *temp = head;

    head = head -> next;
    delete temp;

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

    head = ins_end (head, 10);
    head = ins_end (head, 20);
    head = ins_end (head, 30);
    head = ins_end (head, 40);

    print (head);

    head = delete_head (head);
    head = delete_head (head);
    cout << "\nAfter Deleting 2 heads: ";
    print (head);

    return 0;
}
