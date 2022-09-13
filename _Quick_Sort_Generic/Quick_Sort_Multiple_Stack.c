#include<stdio.h>
#include<stdlib.h>
typedef struct _StackNode__
{
int data;
struct _StackNode__ *next;
}StackNode;

typedef struct __stack_
{
StackNode *top;
int size;
} Stack;

void initStack( Stack *stack)
{
stack->top = NULL;
stack->size = 0;
}

void push(Stack *stack , int data)
{
StackNode *t;
t= (StackNode*)malloc(sizeof(StackNode));
t->data= data;
t->next = stack->top;
stack->top = t;
stack->size++;
}


int pop(Stack *stack)
{
int data;
StackNode *t;
data = stack->top->data;
t =stack->top;
stack->top = stack->top->next;
stack->size--;
free(t);
return data;
}

int isEmpty(Stack *stack)
{
return stack->size == 0;
}

int Partition_Point( int *x , int lb , int ub)
{
int e,f,g;
e=lb;
f= ub;
while(e<f)
{
while(e <ub && x[e] <= x[lb]) e++;
while( x[f] > x[lb]) f--;
if(e<f)
{
g= x[e];
x[e] = x[f];
x[f] = g;
}
else
{
g= x[lb];
x[lb] = x[f];
x[f] = g;
}
}
return f;
}

void Quick_Sort( int *x , int lowerbound , int upperbound)
{
Stack lbstack , ubstack;
int lb,ub, pp;
initStack(&lbstack);
initStack(&ubstack);
push(&lbstack , lowerbound);
push(&ubstack , upperbound);
while(!isEmpty(&lbstack))
{
lb = pop(&lbstack);
ub = pop(&ubstack);
pp = Partition_Point( x,lb,ub);
if(pp+1 <ub)
{
push(&lbstack , pp+1);
push(&ubstack , ub);
}
if(lb < pp-1)
{
push(&lbstack , lb);
push(&ubstack , pp-1);
}
}
}

int main ()
{
int y,x[10];
for(y=0; y<=9; y++)
{
printf(" ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
Quick_Sort(x,0,9);
for(y=0; y<=9 ; y++)
{
printf("%d\n", x[y]);
}
return 0;
}

