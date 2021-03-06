//
//  Header.h
//  SinglyLinkedlist
//
//  Created by venkata bethamcharla on 5/1/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#ifndef Header_h
#define Header_h

#define sprint(expr)          printf(#expr)
#define dprint(expr, val)     printf(#expr": %d \n", val)
#define print_ll(val)         printLinkedlist(val)

typedef int dataType;

struct Node
{
    dataType data;
    struct Node* next;
};

struct Node * create_LinkedList(dataType data);
struct Node * InsertNodeAtBeginningOfList(struct Node *list, dataType data);
struct Node * InsertNodeAtPositionInList(struct Node *list, dataType data, int pos);
struct Node * DeleteNodeAtPositionInList(struct Node *list, int pos);
struct Node * DeleteLinkedList(struct Node * list);
struct Node * ReverseSinglyLinkedList(struct Node *list);
struct Node * NthNodeFromEndOfList(struct Node *list, int n_Node);
int DoesLinkedListHasLoop(struct Node *list);
struct Node * getLastNode (struct Node *list);
struct Node *FindStartNodeOftheLoop(struct Node *list);
int CountNumberOfNodesInLoop(struct Node *list);


struct Node * getNthNode(struct Node * list, int k);
struct Node * reverse_a_single_block(struct Node * list, struct Node * next_head, int k);
struct Node * reverseBlocksOfLinkedList(struct Node * list, int k);
int find_list_length(struct Node *list);
void printLinkedlist(struct Node *list);

void reverse_list(struct Node *list, struct Node *connect);
struct Node * ReverseSecondHalfOfList(struct Node *list);


// Test code
void testCode_p1(void);
void testCode_p2(void);
void testCode_p3(void);
void testCode_p4(void);
void testCode_p5(void);
void testCode_p6(void);
void testCode_p7(void);
void testCode_p8(void);
void testCode_p9(void);



#endif /* Header_h */
