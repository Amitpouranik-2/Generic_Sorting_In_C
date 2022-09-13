#include<stdio.h>
#include<stdlib.h>
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;

typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;

void  InitQueue(Queue *queue)
{
queue->start = NULL;
queue->end =NULL;
queue->size= 0;
}

int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}


void AddToQueue(Queue *queue , int num)
{
QueueNode *t;
t = (QueueNode *)malloc(sizeof(QueueNode));
t->num = num;
t->next = NULL;
if(queue->start== NULL)
{
queue->start = t;
queue->end = t;
}
else
{
queue->end->next =t;
queue->end =t;
}
queue->size++;
}

int RemoveFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num = queue->start->num;
t= queue->start;
queue->start = queue->start->next;
free(t);
queue->size--;
return num;
}

void ClearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t= queue->start;
queue->start = queue->start->next;
queue->size--;
free(t);
}
queue->end = NULL;
queue->size =0;
}

// MAIN FUNCTION
int main ()
{
int x[10], y,e,f,i,num,largest,dc,k;
Queue queue[10];

for(int i=0; i<=9; i++) InitQueue(&queue[i]);


for(y=0; y<=9;y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
largest= x[0];
for(y=1; y<=9; y++)
{
if(x[y] > largest ) largest = x[y];
}
dc= 1;
num =largest;
while(num >9)
{
num = num/10;
dc++;
}
e=10;
k=1;
f=1;
while(k<=dc)
{
y=0;
while(y<=9)
{
num= x[y];
i = (num %e)/f;
AddToQueue(&queue[i] , num);
y++;
}
i=0;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queue[y]))
{
num = RemoveFromQueue(&queue[y]);
x[i] = num++;
i++;
}
y++;
}
e= e*10;
f= f*10;
k++;
}

for(y=0; y<=9; y++)
{
printf("%d\n" , x[y]);
}
return 0;
}