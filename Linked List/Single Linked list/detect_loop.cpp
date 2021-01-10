#include <bits/stdc++.h>
using namespace std;

struct node {
    int n;
    node *next;
    bool visited;

    node (int d) {
        n = d;
        next = NULL;
        visited = false;
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

/* O (n) with hash approach.
 * No need to add a "visited" field in structure
 * No need to point next of all nodes to temp (destroy the references/links)
 * Time complexity: O (n) solution
 * Drawback: O (n) aux space
 * */
bool detect_loop (node *head) {
    unordered_set <node *> uset;

    for (node *cur = head; cur != NULL; cur = cur -> next) {
        if (uset. find (cur) != uset. end ()) {
            return true;
        }

        uset. insert (cur);
    }

    return false;
}

void print (node *head) {
    while (head != NULL) {
        cout << head -> n << " ";
        head = head -> next;
    }

    cout << endl;
}

int main() {
	node *head=new node(15);
	head->next=new node(10);
	head->next->next=new node(12);
	head->next->next->next=new node(20);
	head->next->next->next->next=head->next; // cycle

    cout << "\n" << detect_loop (head) << "\n";

    return 0;
}
