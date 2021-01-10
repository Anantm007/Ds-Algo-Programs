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

// O (n), can also return void
node *remove_duplicates_sorted (node *head) {
    if (head == NULL) {
        return NULL;
    }

    node *cur = head;

    while (cur -> next != NULL) {
        if (cur -> n == cur -> next -> n) { // remove a duplicate node and update the links
            node *temp = cur -> next;
            cur -> next = temp -> next;
            delete temp;
        } else {
            cur = cur -> next;
        }
    }

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
    head = ins_end (head, 10);
    head = ins_end (head, 15);
    head = ins_end (head, 20);
    head = ins_end (head, 30);
    head = ins_end (head, 40);
    head = ins_end (head, 40);
    head = ins_end (head, 40);
    head = ins_end (head, 40);
    head = ins_end (head, 60);

    print (head);
    
    head = remove_duplicates_sorted(head);
    print (head);

    return 0;
}
