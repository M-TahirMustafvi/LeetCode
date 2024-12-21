// Same Binary Tree or not!
#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }

        if(!p && q or !q && p or p->val != q->val) {
            return false;
        }

        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};

int main() {
    Solution solution;

    TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* tree3 = new TreeNode(1, new TreeNode(2), new TreeNode(4));

    cout << "Tree1 and Tree2 are the same: " << solution.isSameTree(tree1, tree2) << endl;
    cout << "Tree1 and Tree3 are the same: " << solution.isSameTree(tree1, tree3) << endl;

    // Clean up memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree3->left;
    delete tree3->right;
    delete tree3;

    return 0;
}