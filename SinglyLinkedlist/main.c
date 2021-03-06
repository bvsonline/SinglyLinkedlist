//
//  main.c
//  SinglyLinkedlist
//
//  Created by venkata bethamcharla on 4/24/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Header.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    testCode_p1();
    
    testCode_p2();
    
    testCode_p3();
    
    testCode_p4();
    
    testCode_p5();
    
    testCode_p6();
    
    testCode_p7();
    
    testCode_p8();
    
    testCode_p9();
    
    return 0;
}

/*
 
 A linked list is a data structure for storing collection of data.
 
 Advantages of arrays:
 Simple and fast to use
 Faster access to the elements
 
 Disadvantages of arrays:
 Preallocates all needed memory upfornt and waste memory space for indices in
 array that are empty.
 Fixed size: The size of array is static.
 One block allocation: To allocate array itself at the beginning, sometimes it
 may not be possible to get the memory for the complete array.
 
 */

void testCode_p1()
{
    sprint(test case: Creation of list and return list length \n);
    struct Node* ll;
    dataType data = 1;
    int ll_len = 0;
    ll = create_LinkedList(data);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    DeleteLinkedList(ll);
}

void testCode_p2()
{
    sprint(test case: Creation of list and insert element at beginning of list);
    struct Node* ll;
    dataType data = 1;
    int ll_len = 0;
    ll = create_LinkedList(data);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    sprint(insert new element at head of list);
    data = 10;
    ll = InsertNodeAtBeginningOfList(ll, data);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    DeleteLinkedList(ll);
}

void testCode_p3()
{
    sprint(test case: Creation of list and insert element at position of list);
    sprint(beginning of list = 0; end of list = -1);
    struct Node* ll;
    dataType data = 1;
    int ll_len = 0;
    int pos = 0;
    ll = create_LinkedList(data);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    sprint(insert new element at head of list);
    data = 10;
    pos = 0;
    ll = InsertNodeAtPositionInList(ll, data, 0);
    print_ll(ll);
    
    sprint(insert new element at end of list);
    data = 25;
    pos = -1;
    ll = InsertNodeAtPositionInList(ll, data, -1);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    DeleteLinkedList(ll);
}

void testCode_p4()
{
    sprint(test case: Creation of list and delete Node in list by position);
    sprint(beginning of list = 0; end of list = -1);
    struct Node* ll;
    dataType data = 1;
    int ll_len = 0;
    int pos = 0;
    ll = create_LinkedList(data);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    sprint(insert new element at head of list);
    data = 10;
    pos = 0;
    ll = InsertNodeAtPositionInList(ll, data, 0);
    
    sprint(insert new element at head of list);
    data = 20;
    pos = 0;
    ll = InsertNodeAtPositionInList(ll, data, 1);
    
    sprint(insert new element at head of list);
    data = 30;
    pos = 0;
    ll = InsertNodeAtPositionInList(ll, data, 2);
    
    sprint(insert new element at head of list);
    data = 40;
    pos = 0;
    ll = InsertNodeAtPositionInList(ll, data, 3);
    print_ll(ll);
    
    sprint(delete node at end of list);
    pos = -1;
    ll = DeleteNodeAtPositionInList(ll, pos);
    
    sprint(delete node at end of list);
    pos = 0;
    ll = DeleteNodeAtPositionInList(ll, pos);
    print_ll(ll);
    
    ll_len = find_list_length(ll);
    dprint(list length, ll_len);
    
    DeleteLinkedList(ll);
}

void testCode_p5()
{
    sprint(test case: reverse singly linked list);
    struct Node* ll;
    dataType data = 1;
    int pos = -1;
    ll = create_LinkedList(data);
    print_ll(ll);
    
    sprint(insert new element at head of list);
    data = 10;
    ll = InsertNodeAtPositionInList(ll, data, pos);
    
    data = 20;
    ll = InsertNodeAtPositionInList(ll, data, pos);
    
    data = 30;
    ll = InsertNodeAtPositionInList(ll, data, pos);
    
    data = 40;
    ll = InsertNodeAtPositionInList(ll, data, pos);
    
    data = 50;
    ll = InsertNodeAtPositionInList(ll, data, pos);
    
    print_ll(ll);
    
    sprint(reverse singly linked list);
    ll = ReverseSinglyLinkedList(ll);
    print_ll(ll);
    
    DeleteLinkedList(ll);
    
}

void testCode_p6()
{
    sprint(test case: get Nth Node from end of list);
    struct Node* ll;
    dataType data_values[20] = {1,   2,  3,  4,  5,  6,  7,  8,  9, 10,
                                11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    dataType *data = data_values;
    
    int pos = -1;
    ll = create_LinkedList(*data++);
    print_ll(ll);
    
    sprint(insert new element at head of list);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);

    struct Node * nth_node = NthNodeFromEndOfList(ll, 6);
    print_ll(nth_node);
    
    DeleteLinkedList(ll);
}

void testCode_p7()
{
    sprint(test case: test if loop exists in list if so find the first node in loop);
    struct Node* ll;
    dataType data_values[20] = {1,   2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    dataType *data = data_values;
    
    int pos = -1;
    ll = create_LinkedList(*data++);
    print_ll(ll);
    
    sprint(insert new element at head of list);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    
    struct Node * nth_node = NthNodeFromEndOfList(ll, 6);
    print_ll(nth_node);
    
    struct Node * last_node = getLastNode(ll);
    
    last_node->next = nth_node;
    
    int is_loop_in_list = DoesLinkedListHasLoop(ll);
    dprint(is loop exist in ll, is_loop_in_list);
    
    FindStartNodeOftheLoop(ll);
    
    int nodeCntinLoop = CountNumberOfNodesInLoop(ll);
    
    dprint(number of nodes in loop, nodeCntinLoop);
    
    if (is_loop_in_list)
    {
        last_node->next = NULL;
    }
    
    DeleteLinkedList(ll);
    
}

void testCode_p8()
{
    sprint(test case: reverse block of k nodes in list of length n; k <= n);
    struct Node* ll;
    dataType data_values[20] = {1,   2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    dataType *data = data_values;
    
    int pos = -1;
    ll = create_LinkedList(*data++);
    print_ll(ll);
    
    sprint(insert new element at head of list);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    
    print_ll(ll);
    
    ll = reverseBlocksOfLinkedList(ll, 4);
    
    print_ll(ll);
    
    DeleteLinkedList(ll);
    
}

void testCode_p9(void)
{
    sprint(test case: reverse second half of list \n);
    struct Node* ll;
    dataType data_values[20] = {1,   2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    dataType *data = data_values;
    
    int pos = -1;
    ll = create_LinkedList(*data++);
    print_ll(ll);
    
    sprint(insert new element at head of list);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
    ll = InsertNodeAtPositionInList(ll, *data++, pos);
  
    print_ll(ll);
    
    ll = ReverseSecondHalfOfList(ll);
    
    print_ll(ll);
    
    DeleteLinkedList(ll);
}
