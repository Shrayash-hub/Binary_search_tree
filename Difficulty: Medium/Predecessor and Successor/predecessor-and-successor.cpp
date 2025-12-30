/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* temp = root; 
    
        while (temp != NULL) {
            if (temp->data < key) {
            // move right to find a larger value still < key
            pre = temp;
            temp = temp->right;
            } 
            else if (temp->data > key) {
                // move left to find a smaller value still > key
                suc = temp;
                temp = temp->left;
            } 
            else {
                // Found the key! 
                // The predecessor is the rightmost child of the left subtree
                // The successor is the leftmost child of the right subtree
            
                // Go to left subtree for Predecessor
                Node* leftSub = temp->left;
                while (leftSub) {
                    pre = leftSub;
                    leftSub = leftSub->right;
                }
            
                // Go to right subtree for Successor
                Node* rightSub = temp->right;
                while (rightSub) {
                    suc = rightSub;
                    rightSub = rightSub->left;
                }
                break; 
            }
        }
    
        ans.push_back(pre);
        ans.push_back(suc);
        return ans;
    }
};