//Problem 1

**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = dummy;
    struct ListNode* curr = head; 

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;  
            free(curr);  
            curr = prev->next; 
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    struct ListNode* newHead = dummy->next;
    free(dummy); 
    return newHead;
}


struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


void printList(struct ListNode* head) {
    printf("[");
    while (head != NULL) {
        printf(" %d ", head->val);
        head = head->next;
    }
    printf("]\n");
}


struct ListNode* makList(int length) {
    if (length <= 0) {
        printf("[]\n");
        return NULL;
    }

    int val;
    printf("Enter value for node 1: ");
    scanf("%d", &val);
    struct ListNode* head = createNode(val);
    struct ListNode* curr = head;

    for (int i = 2; i <= length; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        curr->next = createNode(val);
        curr = curr->next;
    }

    return head;
}


