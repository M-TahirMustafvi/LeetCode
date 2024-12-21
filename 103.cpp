// zig-zag traversal
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> nodesQueue;   
        nodesQueue.push(root);
        bool leftToRight = true;

        while(!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++)
            {
                TreeNode* currNode = nodesQueue.front();
                nodesQueue.pop();

                int index = leftToRight ? i: size - 1 - i;
                row[index] = currNode -> val;

                if(currNode -> left)
                    nodesQueue.push(currNode -> left);
                if(currNode -> right)
                    nodesQueue.push(currNode -> right);
            }
            leftToRight = !leftToRight; 
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}