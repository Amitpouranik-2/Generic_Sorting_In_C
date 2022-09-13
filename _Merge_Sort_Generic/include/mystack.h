#ifndef __mystack__
#define __mystack__ 123
#include<myconst.h>
#include<mymerge.h>
typedef  struct __stack_node
{
void  *ptr;
struct __stack_node *next;
}StackNode;
typedef struct _stack
{
StackNode *top;
int elementsize;
int size;
}Stack;

void initStack(Stack *stack , int elementsize , int *successful  , int *error);
void Push(Stack *stack , void *ptr , int *successful , int *error);
void Pop(Stack *stack , void *ptr, int *successful , int *error);
int isEmpty(Stack *stack , int *successful , int *error);
void clearStack(Stack *stack , int *successful , int *error);
#endif