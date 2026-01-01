/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node* root, int &ans){
        if(!root)
            return {1, 0, INT_MAX, INT_MIN}; 
            // isBST, size, min, max
        
        auto left  = solve(root->left, ans);
        auto right = solve(root->right, ans);
        
        // Check BST condition
        if(left[0] && right[0] && root->data > left[3] && root->data < right[2]){
            int currSize = left[1] + right[1] + 1;
            ans = max(ans, currSize);
            return {1, currSize,
                    min(root->data, left[2]),
                    max(root->data, right[3])};
        }
        
        // Not BST
        return {0, 0, INT_MAX, INT_MIN};
    }
    
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};