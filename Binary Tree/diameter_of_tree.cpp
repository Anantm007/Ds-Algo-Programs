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

// Compute height of the tree
int height (node * root) {
    if (root == NULL) {
        return 0;
    }

    return (1 + max (height (root -> left), height (root -> right)));
}

/* Return the diameter (maximum difference between any 2 leaf nodes) of the tree 
 * Naive Idea: Find height of left subtree and right subtree for every node
 * Add 1 to it (the node for which we are calculating
 * Find the max of all these
 * Time Complexity: O (n ^ 2)
*/
int diameter (node *root) {
    if (root == NULL) {
        return 0;
    }

    int d1 = 1 + height (root -> left) + height (root -> right);
    int d2 = diameter (root -> left);
    int d3 = diameter (root -> right);

    return max (d1, max (d2, d3));
}

/* Return the diameter (maximum difference between any 2 leaf nodes) of the tree 
 * Less Efficient Idea: Pre compute height of every node and store it in a map
 * Time Complexity: O (n) plus overheads of hash map
 * Space: O (n)
*/

/* Return the diameter (maximum difference between any 2 leaf nodes) of the tree 
 * Best Efficient Idea: Modify the height function to calculate diameter as well
 * This function returns the height but sets the "res" variable as the diameter
 * Time Complexity: O (n)
 * Space Complexity: O (h) 
*/
int res = 0;
int height_new (node *root) {
    if (root == NULL) {
        return 0;
    }

    int lh = height_new (root -> left);
    int rh = height_new (root -> right);

    // Diameter
    res = max (res, lh + rh + 1);

    return 1 + max (lh, rh);
}

int main () {
    node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> left -> left = new node (40);
	root -> left -> right = new node (50);
	root -> right -> right = new node (70);
	root -> right -> right->right = new node (80);

    // cout << diameter (root) << "\n";

    height_new (root);
    cout << res << "\n";

    return 0;
}