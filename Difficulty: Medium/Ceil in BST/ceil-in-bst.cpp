class Solution {
  public:
    int findCeilOf(Node* root,int x,int ceilOf){
        // recursively update the variable ceilof -> as you get the elements greater than the target
        if(root==NULL) return ceilOf;
        
        if(root->data==x){
            return root->data;
        }
        else if(root->data>x){
            ceilOf = root->data;
            // go left to find the smaller one
            return findCeilOf(root->left,x,ceilOf);
            
        }
        else{
            // go right to find the greater one
            return findCeilOf(root->right,x,ceilOf);
            
        }
        
    }
    int findCeil(Node* root, int x) {
        // take a variable that save the encountered elements that are greater than x
        
        int ceilOf = -1;
        ceilOf = findCeilOf(root,x,ceilOf);
        return ceilOf;
    }
};
