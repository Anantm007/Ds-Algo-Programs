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

// O(1)
node *ins_beginning (node *head, int x) {
    if (head == NULL) {
        head = new node (x);
    }

    else {
        node *temp = new node (x);
        temp -> next = head;
        head = temp;
    }

    return head;
}

// O (n)
int search (node *head, int x) {
    if (head == NULL) {
        return -1;
    }

    else {
        node *temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp -> n == x) {
                return pos;
            }
            else {
                pos ++;
                temp = temp -> next;
            } 
        }
    }

    return -1;
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

    head = ins_beginning (head, 10);
    head = ins_beginning (head, 20);
    head = ins_beginning (head, 30);
    head = ins_beginning (head, 40);

    print (head);

    cout << "\nSearch: " << search (head, 20);

    return 0;
}
