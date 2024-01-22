#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node tnode;

tnode * create_node(int val){
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

tnode * create_tree(int val, tnode *root){
    if(root == NULL)
        return create_node(val);
    
    else if(root->val>val)
        root->left = create_tree(val, root->left);
    
    else if(root->val<val)
        root->right = create_tree(val, root->right);
    
    return root;
}

void inorder(tnode *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(tnode *root){
    if(root == NULL)
        return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(tnode *root){
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main() {
    int tree[] = {23,34,2,5,26,15,100,653};
    
    tnode *root = create_node(tree[0]);
    for(int i = 1; i<8; i++)
        root = create_tree(tree[i], root);
    
    cout<<"inorder: ";
    inorder(root);
    cout<<endl;
    
    cout<<"preorder: ";
    preorder(root);
    cout<<endl;
    
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
    
    return 0;
}
