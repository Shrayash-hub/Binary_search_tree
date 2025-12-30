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
    int kthSmallest(TreeNode* root, int k) {
        // until root exist 
        int count = 0;
        int ans = -1;
        while(root){
            // if left doesn't exist , so its included in inorder traversal -> increase the count
            if(root->left==NULL){
                count++;
                if(count==k) ans = root->val;
                root=root->right;
            }
            else{
                // take a current pointer pointing the roots left
                TreeNode* curr = root->left;

                // go to the extreme right of left subtree to create the link
                while(curr->right && curr->right!=root){
                    curr=curr->right;
                }

                // check that link exist or not
                // no link present
                if(curr->right==NULL){
                    // create a link
                    curr->right = root;
                    // and move root to its left for futher traversal
                    root = root->left;
                }
                // if link is present
                else{
                    // break the link as left subtree is already done
                    curr->right = NULL;
                    count++;
                    if(count==k) ans = root->val;
                    // move root to its right
                    root = root->right;
                }
            }
        }
        return ans;
    }
};