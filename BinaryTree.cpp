#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insert(int data,Node* root){
    Node* newNode=new Node(data);
    if(root==NULL){
        root=newNode;
        return root;

    }
    else if(data<root->data){
        root->left=insert(data,root->left);
    }
    else if(data>root->data){
        root->right=insert(data,root->right);
    }
    return root;
}
Node* displayPreorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}
Node* displayInorder(Node* root){
    if(root!=NULL){
        displayInorder(root->left);
        cout<<root->data<<" ";
        displayInorder(root->right);
    }
}
Node* displayPostorder(Node* root){
    if(root!=NULL){
        displayPostorder(root->left);
        displayPostorder(root->right);
        cout<<root->data<<" ";
    }
}
Node* displayDescending(Node* root){
    if(root!=NULL){
        displayDescending(root->right);
        cout<<root->data<<" ";
        displayDescending(root->left);
    }
}


int main(){
    Node *root=NULL;
    root=insert(10,root);
    root=insert(6,root);
    root=insert(14,root);
    root=insert(8,root);
    root=insert(3,root);
    root=insert(16,root);
    root=insert(12,root);
    cout<<"Preorder: ";
    displayPreorder(root);
    cout<<endl<<"Postorder: ";
    displayPostorder(root);
    cout<<endl<<"Inorder: ";
    displayInorder(root);
    cout<<endl<<"DescendingOrder: ";
    displayDescending(root);
return 0;
}
