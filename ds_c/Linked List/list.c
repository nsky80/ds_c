#include<stdio.h>
#include<stdlib.h>

// This can be used to store only 'int' DataType
//append(), insert(), display()
// Compile this file using gcc.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
// compile using  gcc -o list.exe list.c
// for run this file use ./a.exe
// Implementation is based on Python list Data structure.


// A linked list node 
struct Node 
{ 
int data; 
struct Node *next; 
}; 


// This is head and tail of list name as LinkedList
struct LinkedList{
    struct Node *head;
    struct Node *tail;
};


// Shortend the names of structures
typedef struct Node Node;
typedef struct LinkedList LinkedList;


// This fuction is used for free the allocated memory
void free_linked_list(Node* node) {
    while (node) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}


// This will create a node and initialize it with data and NULL and return Pointer to Node
Node* create_node(int node_data) {
    Node* node = malloc(sizeof(Node));
    if(node == NULL){
        printf("Memory Overflow");
        exit(0);
    }
    node->data = node_data;
    node->next = NULL;

    return node;
}


// This function used to append the data at last position of list
void append(LinkedList * list, int data){
    Node *cpt;
    cpt = create_node(data);
    if(list->head == NULL){
        list->head = cpt;
    }
    else{
        list->tail->next = cpt;
    }
    list->tail = cpt;
    return;
}

// Displays the elements of list
void display(Node *node){
    printf("\n");
    while (node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }
    return;
}


// Insert Node at given position return the head 

void insert(LinkedList* list, int data, int position) {
    int cnt = 0;
    Node * node, *ptr, *prev;
     
    node = create_node(data);
    if(position == 0){          // if position is head then head will be changed
        node->next = list->head;
        list->head = node;
    }
    else{
        ptr = list->head;
        prev = ptr;
        while(cnt != position){
            cnt += 1;
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = node;
        node->next = ptr;
    }
  //  return list->head;
}


void main(){
    Node *cpt, *ptr;
    LinkedList *list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->tail = NULL;
    append(list, 10);
    append(list, 20);
    append(list, 65);
    append(list, 204);
    append(list, 24);
    display(list->head);
    insert(list, 45, 3);
    display(list->head);
    insert(list, 69, 0);
    display(list->head);
    append(list, 12);
    display(list->head);
    free_linked_list(list->head);
}