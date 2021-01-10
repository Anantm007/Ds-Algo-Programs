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

// O (n) 
void remove_loop (node *head) {
    node *slow = head, *fast = head;

    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast) {
            break;
        }
    }

    // No loop
    if (slow != fast) {
        return;
    }

    // Remove the loop
    slow = head;

    while (slow -> next != fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }

    fast -> next = NULL;
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

    remove_loop (head);

    print (head);

    return 0;
}
