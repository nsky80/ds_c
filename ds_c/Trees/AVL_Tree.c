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
    struct AVLTreeNode *left;     // Pointer to left child
    int data;
    struct AVLTreeNode *right;      // Pointer to right child
    int height;     // height of tree at that perticular node
};

typedef struct AVLTreeNode AVLNode;     // renaming the structure for simplicity


/////////////////////////////////////////////////////////
// This function is used for finding the height of tree at any node
// return int height
int find_height(AVLNode *root){
    if(!root)
        return -1;   // Node doesn't exist
    else
        return root->height;     
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// This function is used for finding the maximum which required in determining height
int max(int d1, int d2){
    return d1 ? d1 > d2: d2;    
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
// This fuction is used for initializing and assigning data to a newly created node
// Return pointer to newly created node
AVLNode *newNode(int data){
    AVLNode *ptr = (AVLNode *)malloc(sizeof(AVLNode));
    if(!ptr){
        printf("\nStack Overflow");
        return;
    }
    ptr->right = NULL;
    ptr->left = NULL;
    ptr->data = data;
    ptr->height = 0;
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// INORDER Traversal of Tree
void inorder(AVLNode *root){
    if(root)
    {
        inorder(root->left);
        printf(" %d %u %u %u\n", root->data, root, root->left, root->right);
        inorder(root->right);
    }    
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// Left Left Rotation of unbalanced Tree, return pointer to new node
AVLNode *LL_rotation(AVLNode *x){
    AVLNode *w = x->left;      // w points to new root node which is new root after rotation
    x->left = w->right;        // make right child of w to left child of x
    w->right = x;             // make x as right child of w and w is new root of subtree
    x->height = max(find_height(x->left), find_height(x->right))+1; // compare height of both child
    w->height = max(find_height(w->left), find_height(w->right))+1;
    return w;    // Return new root
}
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
// Right Right Rotation of unbalanced Tree, return pointer to new node
AVLNode *RR_rotation(AVLNode *x){
    AVLNode *w = x->right;      // w points to new root node ie axis of rotation
    x->right = w->left;        // left child of w becomes right child of x
    w->left = x;             // make x as right child of w and w is new root of subtree
    x->height = max(find_height(x->left), find_height(x->right))+1; // compare height of both child
    w->height = max(find_height(w->left), find_height(w->right))+1;
    return w;    // Return new root
}
/////////////////////////////////////////////////////////

// driver for testing
AVLNode *newNode(int data){
    AVLNode *ptr = (AVLNode *)malloc(sizeof(AVLNode));
    if(!ptr){
        printf("\nStack Overflow");
        return;
    }
    ptr->right = NULL;
    ptr->left = NULL;
    ptr->data = data;
    ptr->height = 0;
}

// Here this is taken only for illustration purpose
int main(void){
    AVLNode *first, *second, *third, *fourth, *fifth;
    first = newNode(1);
    second = newNode(2);
    third = newNode(3);
    fourth = newNode(4);
    fifth = newNode(5);


    // printf("Height is %d and data is %d", first->height, first->data); 
    printf("Before LL rotations:\n");
    inorder(first);   
    first = LL_rotation(first);
    printf("\nAfter LL rotation:\n");
    inorder(first);
    printf("After inserting 4 and 5 in tree:\n");
    
    free_AVLTree(first);
    return 0;
}