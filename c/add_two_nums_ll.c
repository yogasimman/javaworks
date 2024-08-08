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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* endResult = NULL;
    int value1, value2, result, carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        value1 = (l1 != NULL) ? l1->val : 0;
        value2 = (l2 != NULL) ? l2->val : 0;
        result = value1 + value2 + carry;
        carry = result / 10;
        result = result % 10;

        endResult = insertEnd(endResult, result);

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return endResult;
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
        printf("empty\n");
    }
}


int main() {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    // Creating list1 with values [9, 9, 9, 9, 9, 9, 9]
    list1 = insertEnd(list1, 9);
    list1 = insertEnd(list1, 9);
    list1 = insertEnd(list1, 9);
    list1 = insertEnd(list1, 9);
    list1 = insertEnd(list1, 9);
    list1 = insertEnd(list1, 9);
    list1 = insertEnd(list1, 9);

    // Creating list2 with values [9, 9, 9, 9]
    list2 = insertEnd(list2, 9);
    list2 = insertEnd(list2, 9);
    list2 = insertEnd(list2, 9);
    list2 = insertEnd(list2, 9);

    struct ListNode* list3 = addTwoNumbers(list1, list2);
    display(list3);

    return 0;
}

