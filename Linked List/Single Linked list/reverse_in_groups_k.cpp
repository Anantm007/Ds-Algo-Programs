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

// O (n) time, with O (1) extra space
node *reverse_in_groups (node *head, int k) {
    node *cur = head, *prevFirst = NULL;
    bool isFirstPass = true;

    while (cur != NULL) {
        node *first = cur, *prev = NULL;
        int count = 0;
        
        while (cur != NULL && count < k) {
            node *next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;

            count ++;
        }

        if (isFirstPass) {
            head = prev;
            isFirstPass = false;
        }

        else {
            prevFirst -> next = prev;
        }

        prevFirst = first;
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
    head = ins_end (head, 20);
    head = ins_end (head, 30);
    head = ins_end (head, 40);
    head = ins_end (head, 50);
    head = ins_end (head, 60);
    head = ins_end (head, 70);
    head = ins_end (head, 80);
    head = ins_end (head, 90);
    head = ins_end (head, 100);
    head = ins_end (head, 110);
    print (head);
    
    int k = 3;
    head = reverse_in_groups(head, k);
    print (head);

    return 0;
}
