#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};
struct node **nodeList;

void Insert( int data  , int index)
{
struct node *temp , *t;
temp = (struct node *)malloc(sizeof(struct node));
temp->data = data;

if(nodeList[index] == NULL || data < nodeList[index]->data)
{
temp->next = nodeList[index];
nodeList[index] = temp;
return;
}
else
{
t = nodeList[index];
while(t->next!= NULL && t->next->data < data)
{
t = t->next;
}
temp->next = t->next;
t->next = temp;
}
}
void Pigeon_Hole_Sort( int *x , int lb , int ub)
{
int y,largest , smallest , index , i , range , size;
size = ub-lb +1;
largest = x[0];
smallest = x[0];

for(y= lb+1; y<size; y++)
{
if(largest < x[y]) largest = x[y];
if(smallest > x[y] ) smallest = x[y];
}

range = largest - smallest + 1;
nodeList = (struct node **)malloc(sizeof(struct node *)*range);

for(y=0; y<range; y++)
{
nodeList[y] = NULL;
}
for(y=lb; y<size; y++)
{
index = x[y] - smallest;
Insert( x[y] , index);
}

i=0;
for(y=0; y<range; y++)
{
while(nodeList[y] != NULL)
{
x[i] = nodeList[y]->data;
nodeList[y]  = nodeList[y]->next;
i++;
}
}
free(nodeList);
}

int main ()
{
int *x , y , req;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);

if(req < 0)
{
printf("INVALID REQUIRMENT\n");
return 0;
}

x = (int *)malloc(sizeof(int)*req);
if(x== NULL)
{
printf("UNABLE TO ALLOCATE MEMORY \n");
return 0;
}

for(y=0; y< req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}

Pigeon_Hole_Sort( x , 0, req-1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}
return 0;
}
