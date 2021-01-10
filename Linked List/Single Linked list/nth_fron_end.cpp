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

// O (n) with slow, fast 2 pointer approach
int kth_from_end (node *head, int k) {
    if (head == NULL) {
        return -1;
    }

    node *first = head, *second = head;

    // Move first pointer k nodes ahead beforehand
    for (int i = 0; i < k; i ++) {
        if (first == NULL) {
            return -1;
        }

        first = first -> next;
    }

    // when first reaches the end, second reaches the desired output
    while (first != NULL) {
        first = first -> next;
        second = second -> next;
    }

    return second -> n;
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
    head = ins_end (head, 60);
    head = ins_end (head, 70);

    print (head);

    cout << kth_from_end (head, 2) << "\n";
    cout << kth_from_end (head, 6) << "\n";
    cout << kth_from_end (head, 10) << "\n";

    return 0;
}
