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

// In Order traversal - left -> root -> right
void inorder (node *root) {
if (!root) {
        return;
    }

    inorder  (root -> left);
    cout << root -> data << " ";
    inorder  (root -> right);
}

// Post Order traversal - left -> right -> right
void postorder (node *root) {
    if (!root) {
        return;
    }

    postorder (root -> left);
    postorder (root -> right);
    cout << root -> data << " ";
}

int main () {

	node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> right->left = new node (40);
	root -> right->right = new node (50);

    preorder (root);
    cout << "\n";

    inorder (root);
    cout << "\n";

    postorder (root);
    cout << "\n";

    return 0;
}