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

/** Calculate the size (count of total number of nodes) 
 * Time Complexity: O (n)
 * Space Complexity: O (h)
*/
int size (node *root) {
    if (root == NULL) {
        return 0;
    }

    // Recusrive call for the next child adding 1 as it's own count
    return 1 + size (root -> left) + size (root -> right);
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

    cout << "Size: " << size (root) << "\n";

    return 0;
}