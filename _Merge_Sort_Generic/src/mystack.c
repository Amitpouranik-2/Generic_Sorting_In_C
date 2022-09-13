#include<mystack.h>
#include<stdlib.h>
#include<string.h>

void  initStack( Stack *stack , int elementsize , int *successful , int *error)
{
if(successful !=NULL) *successful = FAILED;
if(error) *error = 0;
if(stack == NULL)
{
if(error) *error  =1;
return;
}
if(elementsize <= 0)
{
if(error) *error  = 2;
return;
}
stack->top = NULL;
stack->elementsize = elementsize;
stack->size = 0;
if(successful) *successful  = SUCCESSFUL;
}

void Push(Stack *stack , void *ptr , int *successful , int *error )
{
StackNode *node;
if(successful) *successful = FAILED;
if(error) *error = 0;
if(stack== NULL) 
{
*error  =1;
return;
}
node = (StackNode *)malloc(sizeof(StackNode));
if(node == NULL)
{
if(error) *error = 3;
return;
}
if(ptr!= NULL)
{
node->ptr = (void *)malloc(stack->elementsize);
if(node->ptr==NULL)
{
free(node);
if(error) *error = 3;
return;
}
memcpy(node->ptr , (const void *)ptr , stack->elementsize );
}
else
{
node->ptr = ptr;
}
node->next = stack->top;
stack->top = node;
stack->size++;
if(successful) *successful = SUCCESSFUL;
}


void Pop(Stack *stack , void *ptr , int *successful , int *error)
{
int j;
StackNode *node;
if(successful) *successful = FAILED;
if(error) *error = 0;
if(stack== NULL || ptr== NULL)
{
if(error) *error =1;
return;
}
if(stack->top == NULL)
{
if(error) *error =4;
return;
}
if(stack->top->ptr == NULL) 
{
for(j=0; j< stack->elementsize ; j++)
{
*((char*)(ptr+j)) = (char)0;
}
}
else
{
memcpy(ptr , (const void *)stack->top->ptr , stack->elementsize);
}
node = stack->top;
stack->top = stack->top->next;
if(node->ptr!= NULL) free(node->ptr);
free(node);
stack->size--;
if(successful) *successful = SUCCESSFUL;
}


int isEmpty(Stack *stack , int *successful , int *error )
{
if(successful) *successful = FAILED;
if(error) *error = 0;
if(stack== NULL) 
{
if(error) *error = 1;
return 1;
}
if(successful) *successful = SUCCESSFUL;
if(stack->size == 0) return 1;
return 0;
}

void clearStack( Stack *stack , int *successful , int *error)
{
StackNode *node;
if(successful) *successful = FAILED;
if(error) *error = 0;
if(stack== NULL) 
{
*error = 1;
return;
}
while(stack->top!= NULL)
{
node = stack->top;
stack->top = stack->top->next;
if(node->ptr != NULL) free(node->ptr);
free(node);
}
stack->size = 0;

if(successful) *successful = SUCCESSFUL;
}

