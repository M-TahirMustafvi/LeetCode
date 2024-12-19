// Max Depth - height - of a tree!
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
public:
    int maxDepth(TreeNode* root) {
        if(!root)  return 0;

        // Finds out the height of left subtree of current node
        int leftHeight = maxDepth(root -> left);
        // Finds out the height of right subtree of current node
        int rightHeight = maxDepth(root -> right);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main()
{
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

    // Create a Solution object
    Solution solution;

    // Find the maximum depth of the tree
    int depth = solution.maxDepth(root);

    // Output the result
    cout << "The maximum depth of the tree is: " << depth << endl;

    // Clean up memory
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}