// Max Path Sum!
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
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
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        maxPathHelper(root, maximum);
        return maximum;
    }
private:
    int maxPathHelper(TreeNode* root, int& maxi) {
        if(!root) return 0;

       int leftSum = max(0, maxPathHelper(root -> left, maxi));  //Do not add node that decrease sum
       int rightSum = max(0, maxPathHelper(root -> right, maxi));

       maxi = max(maxi, leftSum + rightSum + root -> val);

       return root->val + max(leftSum, rightSum);
    }


};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.maxPathSum(root) << endl;
    return 0;
}