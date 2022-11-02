//=============================================================================
//! \brief      Use the linear linked list code to store a randomly generated set of 100 integers.
//!             Now write a routine that will rearrange the list in sorted order of these values.
//!             Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.
//!             How will this work? Compare two adjacent list elements and if they are out of order swap them.
//!             After a first pass the largest element will have bubbled to the end of the list.
//!             Each pass can look at one less element as the end of a list stays sorted.
//!
//! \date       Oct 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *createNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

ListNode *createList(int *arr, int size)
{
    ListNode *head = createNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < size; i++)
    {
        cur->next = createNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void pintList(ListNode *head)
{
    ListNode *cur = head;
    int cnt = 0;
    while (cur != NULL)
    {
        printf("%d -> ", cur->val);
        cur = cur->next;
        cnt++;
        if (cnt % 5 == 0)
            printf("\n");
    }
    printf("\n");
}

// Merge Sort
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = createNode(-1);
    ListNode *cur = dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1)
        cur->next = l1;
    if (l2)
        cur->next = l2;
    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *slow = head, *fast = head, *pre = head;
    // find the middle of the list using two pointers
    while (fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return merge(sortList(head), sortList(slow));
}

int main() {
    int arr[100];
    time_t t;
    srand((unsigned)time(&t)); // Initialize random number generator
    for(int i=0;i<100;i++)
    {
        arr[i] = rand() % MAX_NUM;
    }
    ListNode *head = createList(arr, 100);
    printf("Before sorting:\n");
    pintList(head);
    head = sortList(head);
    printf("After sorting:\n");
    pintList(head);
    return 0;
}

