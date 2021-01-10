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

node *reverse (node *head) {
    node *cur = head;
    node *prev = NULL;

    while (cur != NULL) {
        node *next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;

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
    head = ins_end (head, 50);

    print (head);
    cout << "\n";

    head = reverse (head);
    print (head);
    cout << "\n";
    
    return 0;
}
