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

/* O (1) Floyd Cycle Detection approach
 * Two pointer approach - fast and slow
 * No need to add a "visited" field in structure
 * No need to point next of all nodes to temp (destroy the references/links)
 * Time complexity: O (n) solution
 * Advantage: O (1) aux space (better than hash solution)
 */
bool floyd_cycle_detection (node *head) {
    node *slow = head, *fast = head;

    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast) {
            return true;
        }
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

    cout << floyd_cycle_detection (head) << "\n";

    return 0;
}
