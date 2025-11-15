/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        // code here
        // extreme right node will be the greatest
        while(root->right){
            root=root->right;
        }
        return root->data;
    }

    int findMin(Node *root) {
        
        // code here
        // extreme left node will be the smallest
        while(root->left){
            root=root->left;
        }
        return root->data;
    }
};