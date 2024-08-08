#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
}node;

node* insertEnd(node* root,int x){
    
    if(root != NULL){
        node* inital = root;
        while(root->next != NULL){
            root = root->next;
        }
        node* new_node = (node*) malloc(sizeof(node));
        new_node->value = x;
        new_node->prev = root;
        new_node->next = NULL;
        root->next = new_node;
        return inital;
    }

    root = (node*) malloc(sizeof(node));
    root->next = root->prev = NULL;
    root->value = x;
    return root;
}

node* insertBeg(node* root,int x){
    if(root != NULL){
        node* newnode = (node*) malloc(sizeof(node));
        newnode->value = x;
        newnode->next = root;
        newnode->prev = NULL;
        root->prev = newnode;
        return newnode;
    }
    
    node* newnode = (node*) malloc(sizeof(node));
    newnode->value = x;
    newnode->next = NULL;
    newnode->prev = NULL;
}

node* delete(node* root, int x){
    node* inital = root;
    while(root != NULL){
        if(root->value == x){
            int same = 0;

            if(inital == root) same = 1;
            node* prev = root->prev;
            node* next = root->next;
            if(prev != NULL) prev->next = next;
            if(next != NULL) next->prev = prev;
            int value = root->value;
            free(root);
            return same?next:inital;
        }
        root=root->next;
    }
    printf("the entered value is not present");
    return inital;
}

node* search(node* root, int x){
    while(root != NULL){
        if(root->value == x){
            return root;
        }
        root = root->next;
    }
    return NULL;
}

void display(node* root){
    if(root == NULL){
        printf("Linked List is empty");
    }else{
        printf("\n[");
        int i;
        while(root->next != NULL){
            printf("%d,",root->value);
            root = root->next;
        }
        printf("%d]\n",root->value);
    }
}

node* freeMem(node* root){
    node* prev = NULL;
    while(root != NULL){
        prev = root;
        root = root->next;
        free(prev);
    }
}

int main(){
    node* main = NULL; // here we should initialize the value, else the compiler thinks it is deinitialized
    //when not initalized but trying to initizale a value below (giving a deinitialized value to the function)
    for(int i=10;i>0;i--){
        main = insertBeg(main,i);
    }
    display(main);
    
    for(int i=10;i>0;i--){
        main = insertEnd(main,i);
    }
    display(main);
    main = delete(main,1);
    display(main);
  
    node* modify = search(search(main,10)->next,10);
    modify?modify->value = 11:printf("\nNULL\n");

    display(main);
    freeMem(main);
    return 0;
}