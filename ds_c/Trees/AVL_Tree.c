////////////////////////////////////////////////////////////////
/*
C implementation of AVL(Adelson-Velskii	and	Landis) Tree
Compiler used to compile: gcc.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
Can be compiled from same compiler by following command(You may use your own compiler)
compile using  gcc -o AVL_Tree.exe AVL_Tree.c
for run this file use ./AVL_Tree.exe
 */
////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>


//AVL Tree Declaration
//For implementation purpose, here data is taken as "int", it can be changed as per requirement
struct AVLTreeNode
{
    struct AVLTreeNode *left;
    int data;
    struct AVLTreeNode *right;
    int height;     // height of tree at that perticular node
};

typedef struct AVLTreeNode AVLNode;     // renaming the structure for simplicity


/////////////////////////////////////////////////////////
// This function is used for finding the height of tree at any node
// return int height
int height(AVLNode *root){
    if(!root)
        return -1;   // Node doesn't exist
    else
        return root->height;     
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// This fuction is used for free the allocated memory
void free_AVLTree(AVLNode *root) {
    if(root){
        free_AVLTree(root->left);   // free the left subtree
        free_AVLTree(root->right);   // free the right subtree
        free(root);                  // free current node
    }
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// INORDER Traversal of Tree
void Inorder(AVLNode *root){
    if(root)
    {
        Inorder(root->left);
        printf(" %d", root->data);
        Inorder(root->right);
    }    
}
/////////////////////////////////////////////////////////
// Here this is taken only for illustration purpose
int main(void){
    AVLNode *first, *second, *third;
    first = (AVLNode *)malloc(sizeof(AVLNode));
    second = (AVLNode *)malloc(sizeof(AVLNode));
    third = (AVLNode *)malloc(sizeof(AVLNode));
    if(!first || !second || !third)
        printf("Stack Overflow");
    first->data = 3;
    first->height = 2;
    first->left = second;
    first->right = NULL;
    second->data = 1;
    second->height = -1;
    second->left = NULL;
    second->right = third;
    third->data = 2;
    third->height = 0;
    third->left = NULL;
    third->right = NULL;
    // printf("Height is %d and data is %d", first->height, first->data); 
    Inorder(first);   
    free_AVLTree(first);
    return 0;
}