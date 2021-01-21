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

/** Print the left view of the tree using recursion 
 * Idea: If we do preorder traversal, we will always visit the left most node first
 * We just have to maintain values of the levels we have reached
 * Time Complexity: O (n)
 * Space Complexity: O (h)
*/
int maxLevel = 0; // maximum level we have visited so far (0 is for root)

void left (node *root, int level) {
    if (root == NULL) {
        return;
    }

    if (maxLevel < level) {
        cout << root -> data << " ";
        maxLevel = level;
    }

    left (root -> left, level + 1);
    left (root -> right, level + 1);
}

void print_left_view (node *root) {
    left (root, 1);
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

    print_left_view (root);
    cout << "\n";

    return 0;
}