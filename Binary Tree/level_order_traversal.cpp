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

// Pre Order traversal - root -> left -> right
void preorder (node *root) {
    if (!root) {
        return;
    }

    cout << root -> data << " ";
    preorder (root -> left);
    preorder (root -> right);
}

/** Naive Solution: Calculate height and then print nodes at k distance using a loop
 * We can't use recursion here as the control has to go back level wise and not subtree wise
 * Solution: We will use queueu data structure for this problem
 * Concept: a. Enque an item 
 *          b. print the front of the queue
 *          c. while removing add the next level (it's children)
 * Time Complexity: O (n) or Theta (n)
 * Space Complexity: O (w) where 'w' is width of the BT
 * @TODO: Study the approach to print level order traversal with a new line
 * Hint: Start inserting NULL to queue after each level and while traversing if you encounter NULL then you can print the new line 
*/
void level_order (node *root) {
    if (root == NULL) {
        return;
    }

    queue <node *> q;

    q. push (root);

    while (!q. empty ()) {
        // Get access to the top element and print it 
        node * cur = q. front ();
        q. pop ();

        cout << cur -> data << " ";

        // Push the child items if they are not NULL
        if (cur -> left) {
            q. push (cur -> left);
        }

        if (cur -> right) {
            q. push (cur -> right);
        }
    } 
}

int main () {

    node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> left -> left = new node (40);
	root -> left -> right = new node (50);
	root -> right -> right = new node (70);
	root -> right -> right->right = new node (80);

    // preorder (root);
    // cout << "\n";

    level_order (root);
    cout << "\n";

    return 0;
}