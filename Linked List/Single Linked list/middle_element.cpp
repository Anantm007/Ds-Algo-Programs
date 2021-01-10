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

// O (n) with 2 traversals
int print_middle (node *head) {
    if (head == NULL) {
        return -1;
    }

    int count = 0;
    for (node *cur = head; cur != NULL; cur = cur -> next) {
        count ++;
    }

    node *cur = head;
    for (int i = 0; i < count / 2; i ++) {
        cur = cur -> next;
    }

    return cur -> n;
}


// O (n) with slow, fast pointer approach
int print_middle_optimized (node *head) {
    if (head == NULL) {
        return -1;
    }


    node *slow = head, *fast = head;

    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow -> n;
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
    cout << "Middle: " << print_middle_optimized (head) << "\n";

    head = ins_end (head, 20);
    cout << "Middle: " << print_middle_optimized (head) << "\n";
    
    head = ins_end (head, 30);
    cout << "Middle: " << print_middle_optimized (head) << "\n";
    
    head = ins_end (head, 40);
    cout << "Middle: " << print_middle_optimized (head) << "\n";

    // print (head);
    return 0;
}
