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

/** Print the nodes at a specific  distance "k" from the root 
 * Worst Time Complexity: O (n)
 * Worst Space Complexity: O (height)
*/
void distance_k (node *root, int k) {
    // Base Case 
    if (root == NULL) {
        return;
    }

    // When you have reached the kth distance
    if (k == 0) {
        cout << root -> data << " ";
    }

    // Recusrive call for the next child
    distance_k (root -> left, k - 1);
    distance_k (root -> right, k - 1);
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

    cout << "Nodes at distance " << k << ": ";
    distance_k (root, k);
    cout << "\n";

    return 0;
}