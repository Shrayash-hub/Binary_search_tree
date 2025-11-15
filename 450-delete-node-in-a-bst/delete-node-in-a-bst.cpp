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
    TreeNode* deleteNode(TreeNode* root, int target) {
        if(root==NULL) return NULL;

        if(target<root->val){
            root->left = deleteNode(root->left,target);
            return root;
        }
        else if(target>root->val){
            root->right = deleteNode(root->right,target);
            return root;
        }

        else if(target==root->val){
            // leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            // if node have only one child->left child
            else if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // if node have one child which is right
            else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // when node have both the child we replace the node with either maximum in left subtree or minimum in right subtree -> coz those values can suitably fit at that position
            else{
                TreeNode* parent = root;
                TreeNode* child = root->left;

                while(child->right){
                    parent = child;
                    child = child->right;
                    
                }
                if(root!=parent){
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else{
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
        return root;
    }
};