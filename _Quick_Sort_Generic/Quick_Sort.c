#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
int lb,ub;
struct Node *next;
};
struct Node *top;

int isEmpty()
{
return top==NULL;
}

void push(int lowerbound , int upperbound)
{
struct Node *t;
t= (struct Node *)malloc(sizeof(struct Node));
t->lb =lowerbound;
t->ub =upperbound;
t->next = top;
top =t;
}

void pop(int *lowerbound , int *upperbound)
{
struct Node *t;
*lowerbound = top->lb;
*upperbound = top->ub;
t= top;
top = top->next;
free(t);
}

int Partition_Point( void  *x , int lb , int ub ,int es , int (*p2f)(void * , void*))
{
int e,f;
void *g;
g = (void*)malloc(es);
e =lb;
f= ub;
while(e<f)
{
while( e<ub && p2f(x+ (e*es), x+(lb*es)) <=0) e++;
while( p2f(x+(f*es) , x+(lb*es))>0) f--;
if(e<f)
{
memcpy(g ,(const void *)(x+(e*es)),es);
memcpy(x+(e*es) ,(const void *)(x+ (f*es)) , es);
memcpy(x+(f*es) , (const void *)g ,es);
}
else
{
memcpy(g, (const void *)(x+(lb*es)), es);
memcpy(x+(lb*es) , (const void *)(x+(f*es)) ,es);
memcpy(x+(f*es), (const void *)g ,es);
}
}
free(g);
return f;
}



void Quick_Sort(void *x ,int lowerbound , int upperbound , int es , int (*p2f)(void * , void *))
{
int lb,ub,pp;
push(lowerbound , upperbound);
while(!isEmpty())
{
pop(&lb ,&ub);
pp =Partition_Point( x, lb,ub, es ,p2f);
if(pp+1 < ub) push(pp+1 , ub);
if(lb <pp-1) push(lb ,pp-1);
}
}

int My_Comparator( void *left ,void *right)
{
int *a, *b;
a =(int*)left;
b =(int*)right;
return (*a) - (*b);
}


// MAIN FUNCTION

int main ()
{
int *x, req,y;
top==NULL;

printf("ENTER THE REQUIREMENT:");
scanf("%d", &req);
if(req<= 0)
{
printf("INVALID REQUIREMENT");
return 0;
}
x= (int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("UNABLE TO ALLOCATE MEMORY");
return 0;
}
for(y=0; y<req; y++)
{
printf(" ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
Quick_Sort(x,0, req-1, sizeof(int), My_Comparator);
for(y=0; y<req; y++)
{
printf("%d\n" ,x[y]);
}
return 0;
}















