#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };



struct ListNode* insertEnd(struct ListNode* root , int x){
    struct ListNode* prev = NULL;
    if(root != NULL){
        struct ListNode* inital = root;

        while(root != NULL){
        prev = root;
        root = root->next;
    }
    prev->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    prev->next->val = x;
    prev->next->next = NULL;
    return inital;
    }
    root = (struct ListNode*) malloc(sizeof(struct ListNode));
    root->next = NULL;
    root->val = x;
    return root;

}

void display(struct ListNode* l1) {
    if (l1 != NULL) {
        printf("[");
        while (l1 != NULL) {
            printf("%d", l1->val);
            if (l1->next != NULL) {
                printf(", ");
            }
            l1 = l1->next;
        }
        printf("]\n");
    } else {
        printf("[]\n");
    }
}


//for leetcode

struct Heap{
    int *array;
    int size;
    int capacity;
};
typedef struct Heap heap;

heap* construct(int capacity){
    heap* create = (heap*)malloc(sizeof(heap));
    if(create == NULL){
        printf("Memory error");
        return NULL;
    }
    create->capacity = capacity;
    create->size = 0;
    create->array = (int*)calloc(capacity,sizeof(int));

    if(create->array == NULL){
        printf("Memory error");
        return NULL;
    }

}


int done(int * array,int size){
    for(int i=0;i<size;i++){
        if(array[i] == 0){
            return 0;
        }
    }
    return 1;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    int* array = (int*) calloc(listsSize,sizeof(int));
    while(!done(array,listsSize)){
        
    }   
}