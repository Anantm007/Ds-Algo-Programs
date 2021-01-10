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

int length (node *head) {
    int cnt = 0;

    while (head != NULL) {
        cnt ++;
        head = head -> next;
    }

    return cnt;
}

int intersection (node *head1, node *head2) {
    int l1 = length (head1);
    int l2 = length (head2);


    if (l1 > l2) {
        while (l1 -- > 0) {
            if (head1 == NULL) {
                return -1;
            }

            head1 = head1 -> next;
        } 
    }

    else {
        while (l2 -- > 0) {
            if (head2 == NULL) {
                return -1;
            }
            
            head2 = head2 -> next;
        }
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1 -> n;
        }

        head1 = head1 -> next;
        head2 = head2 -> next;
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
    // node *head1 = NULL, *head2 = NULL;

    // head1 = ins_end (head1, 5);
    // head1 = ins_end (head1, 8);
    // head1 = ins_end (head1, 7);    
    // head1 = ins_end (head1, 10);
    // head1 = ins_end (head1, 12);
    // head1 = ins_end (head1, 15);

    // print (head1);
    // cout << "\n";


    // head2 = ins_end (head2, 9);   
    // head2 = ins_end (head2, 10);
    // head2 = ins_end (head2, 12);
    // head2 = ins_end (head2, 15);

    // print (head2);
    // cout << "\n";

    node* newnode; 

	node* head1 = new node(10); 

	node* head2 = new node(3); 

	newnode = new node(6); 
	head2->next = newnode; 

	newnode = new node(9); 
	head2->next->next = newnode; 

	newnode = new node(15); 
	head1->next = newnode; 
	head2->next->next->next = newnode; 

	newnode = new node(30); 
	head1->next->next = newnode; 

	head1->next->next->next = NULL; 


    cout << intersection (head1, head2) << "\n";
    
    return 0;
}
