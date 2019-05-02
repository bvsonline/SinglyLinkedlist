//
//  singlylinkedlist.c
//  SinglyLinkedlist
//
//  Created by venkata bethamcharla on 5/1/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Header.h"

struct Node* create_LinkedList(dataType element)
{
    struct Node *list;
    list = (struct Node *)malloc(sizeof(struct Node));
    assert(list!=NULL);
    list->data = element;
    list->next = NULL;
    return list;
}

void printLinkedlist(struct Node *list)
{
    
    if (list == NULL)
    {
        printf ("List is Empty \n");
    }
    else
    {
        printf("List elements ");
        while (list != NULL)
        {
            printf("%d --> ", list->data);
            list = list->next;
        }
        printf("NULL \n");
    }
    
    return;
}

int find_list_length(struct Node *list)
{
    int count = 0;
    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    
    return count;
}

struct Node* InsertNodeAtBeginningOfList(struct Node *head, dataType element)
{
    struct Node* NewHead;
    
    NewHead = (struct Node *)malloc(sizeof(struct Node));
    NewHead->data = element;
    NewHead->next = head;
    
    return NewHead;
}

struct Node* InsertNodeAtPositionInList(struct Node *head, dataType element, int position)
{
    //  position = 0    - first/head
    //  position = -1   - last/tail
    //  position =
    
    struct Node* NewNode = (struct Node*) malloc(sizeof(struct Node));
    
    if (position == 0)
    {
        NewNode->data = element;
        NewNode->next = head;
        head = NewNode;
        
        return head;
    }
    
    struct Node* TempNode_0 = head;
    struct Node* TempNode_1 = NULL;
    
    if (position == -1)
    {
        while (TempNode_0 != NULL)
        {
            TempNode_1 = TempNode_0;
            TempNode_0 = TempNode_0->next;
        }
        TempNode_1->next = NewNode;
        NewNode->data = element;
        NewNode->next = NULL;
        
        return head;
    }
    
    int k = 0;
    while ((TempNode_0 != NULL) && (k < position))
    {
        k++;
        TempNode_1 = TempNode_0;
        TempNode_0 = TempNode_0->next;
    }
    if (k == position)
    {
        TempNode_1->next = NewNode;
        NewNode->data = element;
        NewNode->next = NULL;
    }
    else
    {
        printf("Can't insert new node \n");
    }
    
    return head;
    
}


struct Node* DeleteNodeAtPositionInList(struct Node *head, int position)
{
    //  position  = 0  head node
    //  position  = -1 last node
    //
    if (position == 0)
    {
        struct Node *TempNode = head, *TempNode2;
        TempNode2 = TempNode->next;
        free(TempNode);
        head = TempNode2;
        
        return head;
    }
    
    struct Node *NextNode = head, *PrevNode = NULL;
    if (position == -1)
    {
        while(NextNode->next != NULL)
        {
            PrevNode = NextNode;
            NextNode = NextNode->next;
        }
        free(NextNode);
        PrevNode->next = NULL;
        
        return head;
    }
    
    int k = 0 ;
    while ((NextNode->next != NULL) && (k < position))
    {
        k++;
        PrevNode = NextNode;
        NextNode = NextNode->next;
    }
    
    if (k == position)
    {
        PrevNode->next = NextNode->next;
        free(NextNode);
    }
    else
    {
        printf("Can't find position in list \n");
    }
    
    return head;
}

struct Node* DeleteLinkedList(struct Node * list)
{
    //  Delete whole linked list
    struct Node *t;
    
    while (list != NULL)
    {
        t = list;
        list = list->next;
        free(t);
    }
    
    return list;
}

// Find Nth node from the end of linked list
// Time complexity: O(n), Space complexity: O(1)
struct Node *NthNodeFromEndOfList(struct Node *head, int n_Node)
{
    struct Node *NthNode = NULL, *temp = head;
    
    for (int i = 1; i < n_Node; i++)
    {
        if (temp)
        {
            temp = temp->next;
        }
    }
    
    NthNode = head;
    while (temp != NULL)
    {
        temp = temp->next;
        NthNode = NthNode->next;
    }
    
    return NthNode;
}


// Find if given linked list has loop
// Time complexity: O(n), Space complexity: O(1)
int DoesLinkedListHasLoop(struct Node *head)
{
    struct Node *slowPtr = head, *fastPtr = head;
    
    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        fastPtr = fastPtr->next;
        
        if (slowPtr == fastPtr)
        {
            return 1;
        }
    }
    
    return 0;
}

// if there is loop exist in linked list, find the start node of the loop
// Time compexity: O(n), Space Complexity: O(1)
struct Node *FindStartNodeOftheLoop(struct Node *head)
{
    struct Node *slowPtr = head, *fastPtr = head;
    int loop_exist = 0;
    
    while (slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        fastPtr = fastPtr->next;
        
        if (slowPtr == fastPtr)
        {
            loop_exist = 1;
            break;
        }
    }
    
    if (loop_exist == 1)
    {
        slowPtr = head;
        
        while (slowPtr != fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        
        return slowPtr;
    }
    
    return NULL;
}

// if there is loop exist in linked list, find the length of the loop
// Time compexity: O(n), Space Complexity: O(1)
int CountNumberOfNodesInLoop(struct Node *head)
{
    struct Node *slowPtr = head, *fastPtr = head;
    int loop_length = 0, loop_exist = 0;
    
    while (slowPtr && fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        fastPtr = fastPtr->next;
        
        if (slowPtr == fastPtr)
        {
            loop_exist = 1;
            break;
        }
    }
    
    if (loop_exist)
    {
        fastPtr = fastPtr->next;
        while (slowPtr != fastPtr) {
            fastPtr = fastPtr->next;
            loop_length++;
        }
        
        return loop_length;
    }
    
    return 0;
}

// Reverse a singly linked list
// Time complexity : O(n), Space complexity: O(1)
struct Node * ReverseSinglyLinkedList(struct Node *head)
{
    struct Node *temp = NULL, *nextNode = NULL;
    
    while(head)
    {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    
    return temp;
}

// Suppose there are two single linked lists both of which intersect at
// some point and became a single linked list. find merging point for list
// space complexity: O(mn), Space complexity: O(1)
struct Node * findMergePointOfTwoLinearLinkedLists(struct Node *list1, struct Node *list2)
{
    struct Node *list1Ptr = list1, *list2Ptr = list2;
    int find_mergepoint = 0;
    
    while (list1Ptr)
    {
        list2Ptr = list2;
        while(list2Ptr)
        {
            if(list1Ptr->next == list2Ptr->next)
            {
                find_mergepoint = 1;
                break;
            }
            list2Ptr = list2Ptr->next;
        }
        if (find_mergepoint == 1)
            break;
        list1Ptr = list1Ptr->next;
    }
    
    return list1Ptr->next;
}


// Suppose there are two single linked lists both of which intersect at
// some point and became a single linked list. find merging point for list
// Time complexity for finding lengths : O(m) + O(n) ~ O(max(m,n))
// for finding difference O(1)
// for making d steps in longer list O(d)
// Total time complexity O(max(m,n))
struct Node * findMergePointOfTwoLinearLinkedLists_v2(struct Node *list1, struct Node *list2)
{
    int L1 = 0, L2 = 0, diff = 0;
    struct Node *list1Ptr = list1, *list2Ptr = list2;
    
    while (list1Ptr)
    {
        list1Ptr = list1Ptr->next;
        L1++;
    }
    
    while (list2Ptr)
    {
        list2Ptr = list2Ptr->next;
        L2++;
    }
    
    if (L1 > L2)
    {
        list1Ptr = list2; list2Ptr = list1; diff = L2-L1;
    }
    else
    {
        list1Ptr = list1; list2Ptr = list2; diff = L1-L2;
    }
    
    for (int i=0; i<diff; i++)
    {
        list1Ptr = list1Ptr->next;
    }
    
    while (list1Ptr != NULL && list2Ptr != NULL)
    {
        if(list1Ptr == list2Ptr)
            return list1Ptr->next;
        
        list1Ptr = list1Ptr->next;
        list2Ptr = list2Ptr->next;
    }
    
    return NULL;
}

// Find the middle of the linked list
// Time complexity: O(n), Space complexity: O(1)
struct Node * FindtheMiddleNode(struct Node * head)
{
    struct Node *slowPtr = head, *fastPtr = head;
    
    while (fastPtr)
    {
        fastPtr = fastPtr->next;
        if (fastPtr)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
    }
    
    return slowPtr;
}

// Determine if length of linkedlist is Even or Odd
// return 1 for even, 0 for Odd
int IsLengthOfLinkedListEvenOdd(struct Node *head)
{
    while (head && head->next)
    {
        head = head->next->next;
    }
    
    if (head == NULL)
        return 1;
    else
        return 0;
}

// Merge two sorted linked lists
// Time complexity: O(n+m) where n and m are lengths of two lists.
struct Node * MergeTwoSortedLists(struct Node * list1, struct Node * list2)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = newNode;
    
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    
    if (list1 != NULL)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    
    temp = newNode->next;
    free(newNode);
    
    return temp;
}

// Split One big circular list into two equal parts
// If it is Odd numbered list, first list should have one additional node.
// Time complexity: O(n), Space complexity: O(1)

void SplitCircularList(struct Node *head, struct Node **cList1, struct Node **cList2)
{
    struct Node *slowPtr = head, *fastPtr = head, *temp = head;
    while(fastPtr->next != head)
    {
        fastPtr = fastPtr->next;
        if (fastPtr != head)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }
    
    temp = slowPtr->next;
    slowPtr->next = head;
    fastPtr->next = temp;
    
    *cList1 = head;
    *cList2 = temp;
    
    return;
}

// For a given value of K(K>0), reverse the blocks of K nodes in a list
// example: Input: 1 2 3 4 5 6 7 8 9
// for K=2, Output: 2 1 4 3 6 5 8 7 9
// for K=3, Output: 3 2 1 6 5 4 9 8 7
// for K=4, Output: 4 3 2 1 8 7 6 5 9
struct Node * ReverseBlockOfKNodes(struct Node *list, int k)
{
    // find the length of list
    int length = find_list_length(list);
    
    if (length < k)
    {
        // reverse isn't possible
        return list;
    }
    
    struct Node * newHead = GetKPlusOnethNode(list, k-1);
    
    reverseKNodes(list, k, length);
    
    return newHead;
    
}

struct Node * GetKPlusOnethNode(struct Node *head, int k)
{
    while (k)
    {
        head = head->next;
        k--;
    }
    
    return head;
}


int LengthOfList(struct Node *listHead)
{
    int length = 0;
    while (listHead)
    {
        listHead = listHead->next;
        length++;
    }
    
    return length;
}

void reverseKNodes(struct Node * list, int k, int length)
{
    struct Node * current = list, *nextNode = NULL, *prev = NULL;
    int t_iter = length/k, temp_k = k;
    
    while (t_iter)
    {
        prev = GetKPlusOnethNode(current, temp_k);
        while (temp_k)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
            temp_k--;
        }

        temp_k = k;
        t_iter--;

    }
}

//  Given a linked list with even and odd numbers, create an algorithm for making
//  changes to the list in such a way that all even numbers appear at the beginning.
struct Node * CreateEvenFollowedByOddList(struct Node * head)
{
    struct Node *list = head, *prev_elist, *copy_elist, *prev_olist, *copy_olist;
    
    copy_elist = prev_elist = (struct Node *)malloc(sizeof(struct Node *));
    copy_olist = prev_olist = (struct Node *)malloc(sizeof(struct Node *));
    
    prev_olist->next = NULL;
    prev_elist->next = NULL;
    
    while (list)
    {
        if ((list->data % 2) == 0)
        {
            prev_elist->next = list;
            prev_elist = list;
        }
        else
        {
            prev_olist->next = list;
            prev_olist = list;
        }
        list = list->next;
    }
    
    head = copy_elist->next;
    prev_elist->next = copy_olist->next;
    prev_olist->next = NULL;
    
    free(copy_elist);
    copy_elist = NULL;
    free(copy_olist);
    copy_olist = NULL;
    
    return head;
    
}

// Find last node from beginning such that n%k=0
// n = number of elements in list
// k = integer constant
// example: n = 19, k =3, return shoudl be 18th node.
struct Node * FindModularNodeFromBeginning(struct Node *head, int k)
{
    int i = 0;
    if (k <= 0)
        return NULL;
    assert(head != NULL);
    struct Node * modularNode = NULL;
    
    while(head)
    {
        if (i%k == 0)
        {
            modularNode = head;
        }
        head = head->next;
        i++;
    }
    
    return modularNode;
}

// Find firstnode from end such that n%k=0
// n = number of elements in list
// k = integer constant
// example: n = 19, k =3, return shoudl be 16th node.
struct Node * FindModularNodeFromEnd(struct Node *head, int k)
{
    int i=0;
    struct Node * current = head, *modularNode = head;
    for (i=0;i<k;i++)
    {
        current = current->next;
    }
    
    while (!current)
    {
        current = current->next;
        modularNode = modularNode->next;
    }
    return modularNode;
}

// Find root N-th node

// Given two lists A, B are in ascending order
// merge them into new list in ascending order such that
struct Node * alternateMerge(struct Node *l1, struct Node *l2)
{
    struct Node * ml = (struct Node *) malloc(sizeof(struct Node));
    struct Node * temp;
    ml->next = NULL;
    temp = ml;
    
    while (!l1 && !l2)
    {
        temp->next = l1;
        temp = temp->next;
        l1 = l1->next;
        
        temp->next = l2;
        temp = temp->next;
        l2 = l2->next;
    }
    
    if (l1)
    {
        temp->next = l1;
    }
    else
    {
        temp->next = l2;
    }
    
    temp = ml->next;
    free(ml);
    ml = NULL;
    return temp;
}



void addListNumbersMain(struct Node *l1, struct Node *l2, struct Node **result);
void addNumbersByRecursion (struct Node *t, struct Node *at, int *c, struct Node **re);
void addRemainingDigits (struct Node *t, int *c, struct Node **re);
// Given two linked lists each list has nodes containing
// single digit integers, with most significant number in head node
//

void addListNumbersMain(struct Node *l1, struct Node *l2, struct Node **result)
{
    struct Node *t1 = l1, *t2 = l2, *t = NULL, *at = NULL, *aat = NULL;
    int l1_len = 0, l2_len = 0, carry = 0, diff = 0;
    while (t1)
    {
        t1 = t1->next;
        l1_len++;
    }
    
    while (t2)
    {
        t2 = t2->next;
        l2_len++;
    }
    
    if (l1_len > l2_len)
    {
        //  l1 has more digits than l2
        t = l1;
        at = l2;
        diff = l1_len-l2_len;
    }
    else if (l2_len > l1_len)
    {
        t = l2;
        at = l1;
        diff = l2_len-l1_len;
    }
    
    if (diff)
    {
        aat = t;
        t = t->next;
    }
    
    addNumbersByRecursion(t, at, &carry, result);
    
    if (diff)
    {
        addRemainingDigits(aat, &carry, result);
    }
    
    if (carry)
    {
        struct Node * r = (struct Node *)malloc(sizeof(struct Node));
        r->data = carry;
        r->next = *result;
        *result = r;
    }
    
    return;
}

void addNumbersByRecursion (struct Node *t, struct Node *at, int *c, struct Node **re)
{
    if (t == NULL)
        return;
    
    addNumbersByRecursion(t->next, at->next, c, re);
    
    int sum = t->data + at->data + *c;
    sum = sum%10;
    *c = sum/10;
    
    struct Node * r = (struct Node *)malloc(sizeof(struct Node));
    r->data = sum;
    r->next = *re;
    *re = r;
}

void addRemainingDigits (struct Node *t, int *c, struct Node **re)
{
    if (t==NULL)
        return;
    addRemainingDigits(t, c, re);
    
    int sum = (t->data) + (*c);
    sum = sum%10;
    *c = sum/10;
    
    struct Node * r = (struct Node *)malloc(sizeof(struct Node));
    r->data = sum;
    r->next = *re;
    *re = r;
}

struct Node * getLastNode (struct Node *list)
{
    assert(!list);
    
    while (list->next)
    {
        list = list->next;
    }
    
    return list;
}
