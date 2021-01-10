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

// O (n), with just one traversal and relative order remains samw
node *segregate (node *head) {
    node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL; // even start, even end, odd start, odd end

    for (node *cur = head; cur != NULL; cur = cur -> next) {
        int x = cur -> n;

        if (x % 2 == 0) {
            if (es == NULL) { // start even number list from here
                es = cur;
                ee = cur;
            }

            else { // Add the node to the even list
                ee -> next = cur;
                ee = ee -> next;
            }
        }

        else {
            if (os == NULL) { // start odd number list from here
                os = cur;
                oe = cur;
            }

            else { // Add the node to the odd list
                oe -> next = cur;
                oe = oe -> next;
            }
        }
    }

    if (os == NULL || es == NULL) {
        return head;
    }

    // Combine the even and odd lists (append odd at end of even)
    ee -> next = os;
    oe -> next = NULL;

    return es;
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
    head = ins_end (head, 25);
    head = ins_end (head, 3);
    head = ins_end (head, 4);
    head = ins_end (head, 58);
    head = ins_end (head, 0);
    head = ins_end (head, 135);
    
    print (head);
    cout << "\n";
    
    head = segregate (head); 

    print (head);
    cout << "\n";

    return 0;
}
