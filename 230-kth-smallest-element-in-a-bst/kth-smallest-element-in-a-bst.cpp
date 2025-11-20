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
    void SmallestK(TreeNode* root,int k,int &count,int &kthsmallest){
        if(root==NULL) return;
        // using preorder traversal -> as it is a property of BST , that preorder of BST is always in sorted order
        SmallestK(root->left,k,count,kthsmallest);
        count++;
        if(count==k) {
            kthsmallest = root->val;
            return ;
        }
        SmallestK(root->right,k,count,kthsmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int kthsmallest = INT_MIN;
        int count = 0;
        SmallestK(root,k,count,kthsmallest);
        return kthsmallest;
    }
};