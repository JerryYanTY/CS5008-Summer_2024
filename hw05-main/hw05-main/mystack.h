// =================== Support Code =================
// Stack
//
//
//
// - Implement each of the functions to create a working stack.
// - Do not change any of the function declarations
//   - (i.e. stack_t* create_stack() should not have additional arguments)
// - You should not have any 'printf' statements in your stack functions. 
//   - (You may consider using these printf statements to debug, 
//      but they should be removed from your final version)
// ==================================================
#include <stdlib.h>
#ifndef MYSTACK_H
#define MYSTACK_H

// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)
# define MAX_DEPTH 32

// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
}node_t;

// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes. No empty nodes should be used. 
typedef struct stack{
	int count;		// count keeps track of how many items
				// are in the stack.
	unsigned int capacity;	// Stores the maximum size of our stack
	node_t* head;		// head points to a node on the top of our stack.
}stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The stacks fields should also be initialized to default values.
stack_t* create_stack(unsigned int capacity){
    if (capacity > MAX_DEPTH){
        exit(1);
    }stack_t* myStack = malloc(sizeof(node_t)*MAX_DEPTH);
    myStack->capacity = capacity;
    myStack->head = NULL;
    myStack->count = 0;
	return myStack;
}

// Stack Empty
// Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element enqueued)
int stack_empty(stack_t* s){
	if (s->count == 0){
        return 1;
    }
	return 0;
}

// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
// Returns 0 if false (the Stack has more space available to enqueue items)
int stack_full(stack_t* s){
	if (s->count == s->capacity){
        return 1;
    }

	return 0;
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the Stack is full that is an error, but does not crash the program).
int stack_push(stack_t* s, int item){
    if (stack_full(s) == 1){
        return -1;
    }
    node_t *temp = malloc(sizeof(node_t));
    temp->data = item;
    temp->next = s->head;
    s->head = temp;
    s->count ++;
    return 0;
//    if (stack_empty(s) == 1){
//        s->head = temp;
//        s->count += 1;
//        return 0;
//    }
//    else{
//        node_t *curr = s->head;
//        while(curr->next!=NULL){
//            curr = curr->next;
//        }
//        curr->next = temp;
//        s->count +=1;
//        return 0;
//    }
}

// Dequeue an item
// Returns the item at the front of the stack and
// removes an item from the stack.
// Removing from an empty stack should crash the program, call exit(1).
int stack_pop(stack_t* s){
	if (stack_empty(s) == 1){
        exit(1);
    }
    else{
        node_t *temp = s->head;
        s->head = s->head->next;
        int result = temp->data;
        free(temp);
        s->count -=1;
        return result;
    }
}

// Stack Size
// Queries the current size of a stack
// A stack that has not been previously created will crash the program.
// (i.e. A NULL stack cannot return the size)
unsigned int stack_size(stack_t* s){
    if (s== NULL)
    {exit(1);}

	return s->count;
}

// Free stack
// Removes a stack and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_stack(stack_t* s){
	node_t* temp;
    while(s->head!=NULL){
        temp = s->head;
        s->head = s->head->next;
        free(temp);
    }
}

#endif
