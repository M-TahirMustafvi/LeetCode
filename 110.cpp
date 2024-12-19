// Check Height Balance
#include<iostream>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int checkHeight(TreeNode* root) {
        if(!root) return 0;

        int left = checkHeight(root -> left);
        if(left == - 1) return -1;
        int right = checkHeight(root -> right);
        if(right == - 1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1+ max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

int main() {
    // Create nodes of the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    /*
        Tree Structure:
               1
             /   \
            2     3
           / \      \
          4   5      6
                        \
                         7
    */

    // Create Solution object
    Solution solution;

    // Check if the tree is balanced
    if (solution.isBalanced(root)) {
        cout << "The tree is height-balanced." << endl;
    } else {
        cout << "The tree is not height-balanced." << endl;
    }

    // Clean up memory
    delete root->right->right->right; // Delete node 7
    delete root->right->right;       // Delete node 6
    delete root->right;              // Delete node 3
    delete root->left->right;        // Delete node 5
    delete root->left->left;         // Delete node 4
    delete root->left;               // Delete node 2
    delete root;                     // Delete root node (1)

    return 0;
}