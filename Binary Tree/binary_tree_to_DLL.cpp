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

/** Convert a binary tree into a doubly linked list. The ordering should be inorder
 * left should be the previous pointer and right should be the next pointer
 * Time Complexity: O (n)
 * Space Complexity: O (h)
*/
node *bt_to_dll (node *root) {
    if (root == NULL) {
        return root;
    }
    
    static node *prev = NULL;

    // Left
    node *head = bt_to_dll (root -> left);

    // Process right
    if (prev == NULL) {
        head = root;
    }

    else {
        root -> left = prev;
        prev -> right = root;
    }

    prev = root;
    
    // Right
    bt_to_dll (root -> right);

    return head;
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

    node *head =  bt_to_dll (root);

    print_list (head);
    cout << "\n";

    return 0;
}