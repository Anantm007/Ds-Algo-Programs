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

void print (node *&head) {
    while (head != NULL) {
        cout << head -> n << " ";
        head = head -> next;
    }

    cout << endl;
}

int main() {
    node *head = new node (10);
    head -> next = new node (20);
    head -> next -> next = new node (30);
    head -> next -> next -> next = new node (40);

    print (head);
    print (head);

    return 0;
}
