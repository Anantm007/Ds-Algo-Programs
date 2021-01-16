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

int height (node *root) {
    if (root == NULL) {
        return 0;
    }

    return (max (height (root -> left), height (root -> right)) + 1);
}


int main () {

	node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> right->left = new node (40);
	root -> right->right = new node (50);

    preorder (root);
    cout << "\n";

    cout << "Height: " << height (root) << "\n";

    return 0;
}