#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node (int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/* Print the binary tree spiral order wise
 * Spiral Order: i. Root
 *               ii. Even rows (consider first as 1 odd) - print right to left
 *               iii. Odd rows - print left to right
 * Method 1: Using Stack and Queue and using level order traversal approach
 * If we need to print reverse order wise then push the items into stack and pop later
 * Time Complexity: O (n)
*/
void spiral (node *root) {
     if(root == NULL) {
         return;
    }

    queue <node *> q;
    stack <int> s;

    bool reverse = false;
    q. push (root);

    while (q. empty () == false) {
        int count = q. size ();

        for (int i = 0; i < count; i ++) {
            node *curr = q. front ();
            q. pop ();

            if (reverse) {
                s. push (curr -> data);
            }

            else {
                cout << curr -> data << " ";
            }

            if(curr -> left != NULL) {
                q. push (curr -> left);
            }

            if(curr -> right != NULL) {
                q. push (curr -> right);
            }
        }

        if (reverse) {
            while(s. empty () == false) {
                cout << s. top () << " ";
                s. pop ();
            }
        }

        reverse = !reverse;
    }
}

/** Method 2
 * Use 2 stacks
 * Push the root into stack 1
 * While any of the stacks is not empty:
 * i. while s1 is not empty: pop and print, insert their children
 * ii. while s2 is not empty" pop and print, insert their children 
 * Time Complexity: O (n)
*/
void spiral_optimized (node *root) {
     if (root == NULL) {
        return;  
    } 

    stack <node *> s1;  
    stack <node *> s2;  
  
    s1. push (root); 
  
    while (!s1. empty () || !s2. empty ()) { 
        while (!s1. empty ()) { 
            node *temp = s1. top (); 
            s1. pop (); 
            cout << temp -> data << " "; 
  
            if (temp -> right) 
                s2. push (temp -> right); 
            if (temp -> left) 
                s2. push (temp -> left); 
        } 
        
        while (!s2. empty ()) { 
            node* temp = s2.top(); 
            s2. pop (); 
            cout << temp -> data << " "; 
  
            if (temp -> left) 
                s1. push (temp -> left); 
            if (temp -> right) 
                s1. push (temp -> right); 
        } 
    } 
}

int main () {
    node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> left -> left = new node (40);
	root -> left -> right = new node (50);
	root -> right -> left = new node (60);
	root -> right -> right = new node (70);

    // spiral (root);
    // cout << "\n";

    spiral_optimized (root);
    cout << "\n";

    return 0;
}