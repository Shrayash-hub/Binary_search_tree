#include<iostream>


using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;

    Node(int value){
        data = value;
        left=right=NULL;
    }
};

Node* insert(int target,Node* root){
    // if a root is null , create a temp node with target value
    if(root==NULL){
        Node* temp = new Node(target);
        return temp;
    }

    // if target is smaller than root -> insert it in left node
    if(target<root->data){
        root->left = insert(target,root->left);
    }
    // if target is greater than root -> insert it in right node
    else if(target>root->data){
        root->right = insert(target,root->right);
    }

    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int arr[] = {6,3,17,5,11,18,2,1,29,14};
    Node* root = NULL;

    for(int i=0;i<10;i++){
        root = insert(arr[i],root);
    }
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}