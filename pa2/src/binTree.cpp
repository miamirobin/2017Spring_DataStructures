#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <string>
#include <stdlib.h> 
#include "binTree.h"
// Smaller elements go to left subtree
// larger elements go to right subtree

using namespace std;


/*  insert the key to BST   */
void BinarySearchTree::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    t->data = d;
    // check whether this a new tree?
    if(isEmpty()) root = t;
    else
    {
        // insert key  as leaf node
        tree_node* cur;
        cur = root;
        // find the node's parent
        while(cur)
        {
            parent = cur;
            if(t->data > cur->data) cur = cur->right;
            else cur = cur->left;
        }
        
        if(t->data < parent->data)
            parent->left = t;
        else
            parent->right = t;
    }
}



/*  search the key in BST and return the comparisons needed*/
int BinarySearchTree::search(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    t->data = d;
   
    tree_node* cur;
    cur = root;
    int p=1;
    // Find the Node's parent
    while(cur->data!=t->data)
    {
        
        if(t->data > cur->data) cur = cur->right;
        else cur = cur->left;
        p+=1;
    }
    return p;
    
}




/* print the BST by required way*/
void BinarySearchTree::printTree()
{
    back_inorder(root);
    
}
/* use the reverse order of inorder traversal*/
void BinarySearchTree::back_inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->right) back_inorder(p->right);
        for (int j=0;j<search(p->data);j++){
                cout<<"     ";
        }
        cout<<" "<<p->data<<endl;
        if(p->left) back_inorder(p->left);
    }
    else return;
}




