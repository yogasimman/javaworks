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
typedef struct stack{
    int capacity;
    int pointer;
    struct ListNode** array;
}stack;

stack* construct(int cap){
    stack* create = (stack*) malloc(sizeof(stack));
    create->capacity = cap;
    create->pointer = -1;
    create->array = (struct ListNode**) malloc(sizeof(struct ListNode*)*cap);
    return create;
}

int isEmpty(stack* x){
    return (x->pointer == -1);
}

int isFull(stack* x){
    return (x->pointer == x->capacity-1);
}

void push(stack *x,struct ListNode* node){
    if(!isFull(x)){
        x->array[++x->pointer] = node;
    }
}

struct ListNode* pop(stack *x){
    if(!isEmpty(x)){
        struct ListNode* value = x->array[x->pointer--];
        return value;
    }
    return NULL;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* current = head;
    int count = 0;

    while(current != NULL && count < k){
        current = current->next;
        count++;
    }

    if(count == k){
        stack* temp = construct(k);
        current = head;
        for(int i=0;i<k;i++){
            push(temp,current);
            current = current->next;
        }

        struct ListNode* new_head = pop(temp);
        struct ListNode* new_current = new_head;
        while(!isEmpty(temp)){
            new_current->next = pop(temp);
            new_current = new_current->next;
        }
        new_current->next = reverseKGroup(current,k);
        return new_head;
    }
    return head;
}

int main(){
    struct ListNode* list1 = NULL;
    for(int i=1;i<6;i++){
        list1 = insertEnd(list1,i);
    }
    display(list1);
    list1 = reverseKGroup(list1,3);
    display(list1);
}