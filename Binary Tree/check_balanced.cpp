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

/** Check if the difference between height of left and subtree does not exceed 1 (for every node)
 * Naive Solution: Check for every node recursively
 * Time Complexity: O (n^2) 
 * Space Complexity: O (h)
*/
int height (node *root) {
    if (root == NULL) {
        return 0;
    }

    return (max (height (root -> left), height (root -> right)) + 1);
}

bool is_balanced_naive (node *root) {
    if (root == NULL) {
        return true;
    }

    // O (n)
    int lh = height (root -> left);
    int rh = height (root -> right);

    return (abs (lh - rh) <= 1 && is_balanced_naive (root -> left) && is_balanced_naive (root -> right));
}

/** Check if the difference between height of left and subtree does not exceed 1 (for every node)
 * Better Solution: Return a single integer
 * if integer is -1 then it means subtree is not balanced 
 * else it denotes the height of the subtree
 * Time Complexity: O (n)
 * Space Complexity: O (h)
*/
int is_balanced (node *root) {
    if (root == NULL) {
        return 0;
    }

    // Check left and right subtrees
    int lh = is_balanced (root -> left);
    if (lh == -1) {
        return -1;
    }

    int rh = is_balanced (root -> right);
    if (rh == -1) {
        return -1;
    }

    // Check for balance
    if (abs (lh -rh) > 1) {
        return -1;
    }

    else {
        return max (lh, rh) + 1;
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


    // node *root=new node (20);
	// root -> left = new node (8);
	// root -> right = new node (12);
	// root -> right -> left = new node (3);
	// root -> right -> right = new node (9);

    preorder (root);
    cout << "\n";

    cout << is_balanced_naive (root) << "\n";
    cout << is_balanced (root) << "\n";

    return 0;
}