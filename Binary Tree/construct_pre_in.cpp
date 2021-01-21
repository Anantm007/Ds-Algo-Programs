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

// Print the doubly linked list
void print_list (node *head) {
    node *cur = head;

    while (cur != NULL) {
        cout << cur -> data << " ";
        cur = cur -> right;
    }
}

/** Construct a binary tree when preorder and inorder traversals are given
 * We will construct the tree inorder wise
 * Time Complexity: O (n^2)
*/
node *construct_tree (int in[], int pre [], int is, int ie) {
    if (is > ie) {
        return NULL;
    }

    static int preIndex = 0;

    // Make root from pre order's index
    node *root = new node (pre [preIndex ++]);

    int inIndex;

    // To know what is there in left subtree and what in right subtree
    for (int i = is; i <= ie; i ++) {
        if (in [i] == root -> data) {
            inIndex = i;
            break;
        }
    }

    root -> left = construct_tree (in, pre, is, inIndex - 1);
    root -> right = construct_tree (in, pre, inIndex + 1, ie);

    return root;
}

int main () {
    int in [] = {20, 10, 40, 30, 50};
    int pre [] = {10, 20, 30, 40, 50};

    int n = sizeof (in) / sizeof (in [0]);
    node *root = construct_tree (in, pre, 0, n - 1);


    preorder (root);
    cout << "\n";

    return 0;
}