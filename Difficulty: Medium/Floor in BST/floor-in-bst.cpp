/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int floorOf = -1;
            while(root){
            if(root->data==x){
                floorOf = root->data;
                return floorOf;
            }
            else if(root->data<x){
                floorOf = root->data;
                root = root->right;
            }
            else{
                
                root = root->left;
            }
        }
        return floorOf;
    }
};