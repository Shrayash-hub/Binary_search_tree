/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we know that in BST , left child is smaller and right child is greater than the root node
        if(!root) return NULL;
        TreeNode* curr = root;

        // if both the nodes are smaller than the root then LCA must be at left side
        if(curr->val>p->val && curr->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        // if both the nodes are smaller than the root then LCA must be at right side
        if(curr->val<p->val && curr->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};