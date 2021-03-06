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

/** Print the left view of the tree using iteration 
 * Idea: We do line by line level order traversal with just one extra condition
 * Inside the loop, we print the node only if it's the first node at it's level
 * Time Complexity: O (n)
 * Space Complexity: Theta (width) or O (n) as last width will be n/2
*/
void print_left_view (node *root) {
    if (root == NULL) {
        return;
    }

    queue <node *> q;
    q. push (root);

    while (!q. empty ()) {
        int cnt = q. size ();

        for (int i = 0; i < cnt; i ++) {
            node *cur = q. front ();
            q. pop ();

            if (i == 0) {
                cout << cur -> data << " ";
            }

            if (cur -> left != NULL) {
                q. push (cur -> left);
            }

            if (cur -> right != NULL) {
                q. push (cur -> right);
            }
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
	root -> right -> right -> right = new node (80);

    // preorder (root);
    // cout << "\n";

    print_left_view (root);
    cout << "\n";

    return 0;
}