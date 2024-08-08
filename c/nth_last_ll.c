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

int counter (struct ListNode* root){
    int count = 0;
    while(root != NULL){
        root = root->next;
        count++;
    }
    return count;
}

struct ListNode* deleteIndex(struct ListNode* root,int index){
    struct ListNode* inital = root;
    struct ListNode* prev = NULL;
    int i = 1;
    while(root!=NULL && i < index){
        prev = root;
        root = root->next;
        i++;
    }
    if(root == NULL){
        return inital;
    }
    if(prev == NULL){
        inital = root->next;
        free(root);
    }
    if(prev != NULL){
        prev->next = root->next;
        free(root);
    }
    return inital;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int index = counter(head) - n + 1;
    struct ListNode* inital = deleteIndex(head,index);
    return inital;

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

int main(){
    struct ListNode* list1 = NULL;
    list1 = insertEnd(list1,1);
    display(list1);
    list1 = removeNthFromEnd(list1,1);
    display(list1);
}