//=============================================================================
//! \brief      Modify the singly linked list to be a doubly linked list. 
//!             Now write a routine that removes all duplicate data in the doubly linked list. 
//!             The data will be integers generated at random from [0,49]. Initially have a list of 200 elements.  
//!             Now do this in one of two ways.  
//!             Sort the list by its data field. Remove adjacent elements of the sorted list with the same value. 
//!             Or, take the first element—search the remainder of the list for elements with the same data and remove them. 
//!             Then take the second element and do the same. Repeat until only one element is left.
//!
//! \date       Oct 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NODES 200
typedef struct ListNode
{
    int val;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

ListNode *createNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

ListNode *createList(int *arr, int size)
{
    ListNode *head = createNode(arr[0]);
    ListNode *cur = head;
    ListNode *pre = cur;
    for (int i = 1; i < size; i++)
    {
        cur->next = createNode(arr[i]);
        cur = cur->next;
        cur->prev = pre;
        pre = pre->next;
    }
    return head;
}

void pintList(ListNode *head)
{
    ListNode *cur = head;
    int cnt = 0;
    while (cur != NULL)
    {
        printf("%d <-> ", cur->val);
        cur = cur->next;
        cnt++;
        if (cnt % 5 == 0)
            printf("\n");
    }
    printf("\n");
}

void removeDup(ListNode *head)
{
    ListNode *cur = head;
    ListNode *pre = cur;
    while (cur != NULL)
    {
        while (cur->next != NULL && cur->val == cur->next->val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
        cur = cur->next;
    }
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
            l1->prev = cur;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2->prev = cur;
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

int main()
{
    srand(time(NULL));
    int arr[TOTAL_NODES];
    for (int i = 0; i < TOTAL_NODES; i++)
        arr[i] = rand() % 50;
    ListNode *head = createList(arr, TOTAL_NODES);
    printf("Before sorting:\n");
    pintList(head);
    head = sortList(head);
    printf("After sorting:\n");
    pintList(head);
    removeDup(head);
    printf("After removing duplicates:\n");
    pintList(head);
    return 0;
}
