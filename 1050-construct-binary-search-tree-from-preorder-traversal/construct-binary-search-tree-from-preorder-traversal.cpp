/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int index = 0;
        return build(pre, index, INT_MAX);
    }


    TreeNode* build(vector<int>& pre, int& idx, int bound) {
        
        // If all elements are used OR next value is greater than allowed bound
        if(idx == pre.size() || pre[idx] > bound)
            return NULL;

        // Create node
        TreeNode* root = new TreeNode(pre[idx++]);

        // Left subtree: values must be smaller than root->val
        root->left  = build(pre, idx, root->val);

        // Right subtree: values can go upto previous bound
        root->right = build(pre, idx, bound);

        return root;
    }
};
