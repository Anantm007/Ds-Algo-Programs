#include <iostream>
using namespace std;

// node Structure
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

/** O (n)
 * We will modify the pointers here
 * Another O(n) solution can be swapping the data, but it might hinder scalability when data is complex
*/
node *pairwise_swap (node *head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    node *curr = head -> next -> next;
    node *prev = head;
    head = head -> next;
    head -> next = prev;

    while(curr != NULL && curr -> next != NULL) {
        prev -> next = curr -> next;
        prev = curr;
        node *next = curr -> next -> next;
        curr -> next-> next = curr;
        curr = next;
    }

    prev -> next = curr;
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

    print (head);

    head = pairwise_swap (head);

    print (head);

    return 0;
}
