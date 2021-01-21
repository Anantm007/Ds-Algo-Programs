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

/** Print the number of maximum nodes at any level (width) 
 * Idea: Just like line by line level order traversal insert each level into the queue
 * Check if the size of the queue at current instant is greater than the max width till now 
 * Time Complexity: O (n)
 * Space Complexity: O (n) or Theta (width of every level)
*/
int max_width (node *root) {
    if (root == NULL) {
        return 0;
    }

    queue <node *> q;
    int ans = 0;

    q. push (root);

    while (!q. empty ()) {
        int cnt = q. size ();

        ans = max (ans, cnt);

        for (int i = 0; i < cnt; i ++) {
            node *cur = q. front ();
            q. pop ();

            if (cur -> left) {
                q. push (cur -> left);
            }

            if (cur -> right) {
                q. push (cur -> right);
            }
        }
    }

    return ans;
}

int main () {
    node *root = new node (10);
	root -> left = new node (20);
	root -> right = new node (30);
	root -> left -> left = new node (40);
	root -> left -> right = new node (50);
	root -> right -> left = new node (60);
	root -> right -> right = new node (70);
	root -> right -> right -> right = new node (80);

    preorder (root);
    cout << "\n";

    cout << max_width (root) << "\n";

    return 0;
}