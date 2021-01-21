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

/** Check if the sum of all values of left child and right child equals to the parent node (for every node unless NULL) 
 * Empty and single node tree also follow children sum property
 * Time Complexity: O (n)
 * Space Complexity: O (h)
*/
bool is_child_sum (node *root) {
    if (root == NULL) {
        return true;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return true;
    }

    // Get sum of left and right subtree
    int sum = 0;

    if (left != NULL) {
        sum += root -> left -> data;
    }

    if (right != NULL) {
        sum += root -> right -> data;
    }

    return (root -> data == sum && is_child_sum (root -> left) && is_child_sum (root -> right));
}

int main () {
    node *root=new node (20);
	root -> left = new node (8);
	root -> right = new node (12);
	root -> right -> left = new node (3);
	root -> right -> right = new node (9);

    preorder (root);
    cout << "\n";

    cout << is_child_sum (root);
    cout << "\n";

    return 0;
}