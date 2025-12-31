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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    
    void inOrder(TreeNode* root){
        
        if(root==NULL) return;

        inOrder(root->left);

        if(root!=NULL && (root->val<prev->val)){
            // if it is first foul
            if(first==NULL){
                first=prev;
                middle = root;
            }
            // if its second foul
            else{
                last = root;
            }
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = NULL;
        last = NULL;
        middle = NULL;

        prev = new TreeNode(INT_MIN);

        inOrder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};