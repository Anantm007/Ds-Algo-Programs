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

/** Return the largest value in the tree 
 * Time Complexity: O (n)
 * Space Complexity: O (h)
 * Alternate Solution: Level order traversal using a Queue based approach
*/
int max_in_tree (node *root) {
    if (root == NULL) {
        return INT_MIN;
    }

    return max (max (root -> data, max_in_tree (root -> left)), max_in_tree (root -> right));
}


int main () {
    node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> left -> left = new node (40);
	root -> left -> right = new node (50);
	root -> right -> right = new node (70);
	root -> right -> right->right = new node (80);

    preorder (root);
    cout << "\n";

    int k = 2;

    cout << "Max element: " << max_in_tree (root) << "\n";

    return 0;
}