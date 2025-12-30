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
    // we are going to define a range for each node and if any node is out of its range then its not a bst
    bool helper(TreeNode* root,long long low, long long high){
        if(!root) return true;

        if(root->val<=low || root->val>=high){
            return false;
        }
        // for left child one of the range is defined -> it must be smaller than root
        // similarly for the right child , it must be greater than root

        return helper(root->left,low,root->val) && helper(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        // range of root will be LLONG_MIN and LONG_MAX
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};