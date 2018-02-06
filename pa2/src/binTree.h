#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <string>
#include <stdlib.h> 

/* declare the variables and funtions of BST */
class BinarySearchTree
{

private:
    struct tree_node
    {
        tree_node* left;
        tree_node* right;
        int data;
    };
     tree_node* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty() const { return root==NULL; }
    void insert(int);
    int search(int );
    void printTree();
    void back_inorder(tree_node* );
    
    /* (node rotates to the left)  */
    tree_node* LRotate(tree_node* key)
    {
        tree_node* k1 = key->right;
        key->right = k1->left;
        k1->left = key;
        
        return k1;
    }
    
    /* (node rotates to the right)  */
    tree_node* RRotate(tree_node* key)
    {
        tree_node* k1 = key->left;
        key->left = k1->right;
        k1->right = key;
        return k1;
    }
    
    /* top-down splay tree  method */
    tree_node* Splay(int key,tree_node* root)
    {
        
        tree_node head;
        /* head.right_child points to Left tree
           head.left_child points to Right tree */
        head.left = NULL;
        head.right = NULL;
        tree_node* LeftTree = &head;
        tree_node* RightTree = &head;
        while (true)
        {
            if (key < root->data)
            {
                if (!root->left)
                    break;
                if (key < root->left->data)
                {
                    root = RRotate(root);
                    if (!root->left)
                        break;
                }
                /* Link to Right Tree */
                RightTree->left = root;
                RightTree = RightTree->left;
                root = root->left;
                RightTree->left = NULL;
            }
            else if (key > root->data)
            {
                if (!root->right)
                    break;
                if (key > root->right->data)
                {
                    root = LRotate(root);
                    if (!root->right)
                        break;
                }
                /* Link to Left Tree */
                LeftTree->right = root;
                LeftTree = LeftTree->right;
                root = root->right;
                LeftTree->right = NULL;
            }
            else
                break;
        }
        /* assemble Left Tree, Middle Tree and Right tree */
        LeftTree->right = root->left;
        RightTree->left = root->right;
        root->left = head.right;
        root->right = head.left;
        return root;
    }
    
    /* when search a key, we need to call splay */
    void SplaySearch(int key)
    {
       root= Splay(key,root);
    }

};


