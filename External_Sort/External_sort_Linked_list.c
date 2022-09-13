#include<stdio.h>
#include<stdlib.h>
struct Node 
{
int num;
struct Node *next;
};
struct Node *start;
void addToCollection(int num)
{
struct Node *t;
t= (struct Node *)malloc(sizeof(struct Node));
t->num = num;
t->next =start;
start = t;
}
void printline()
{
struct Node *t;
for(t=start; t; t=t->next)
{
printf("%d\n" , t->num);
}
}

struct Node *merge(struct Node *firstlist , struct Node *secondlist)
{
struct Node *left , *right , *end , *newlist;
if(firstlist == NULL || secondlist== NULL) return NULL;
if(firstlist== NULL) return secondlist;
if(secondlist== NULL) return firstlist;
newlist = NULL;
left = firstlist;
right = secondlist;
while(left && right)
{
if(left->num < right->num)
{
if(newlist == NULL) newlist = left;
else end->next = left;
end = left;
left =left->next;
}
else
{
if(newlist== NULL) newlist = right;
else end->next = right;
end = right;
right = right->next;
}
end->next = NULL;
}
if(left) end->next = left;
if(right) end->next = right;
return newlist;
}


void spilter(struct Node *top , struct Node **firstlist , struct Node **secondlist)
{
struct Node *t , *tt;
if(top == NULL) 
{
*firstlist = NULL;
*secondlist= NULL;
return;
}
if(top->next == NULL)
{
*firstlist = top ;
*secondlist = NULL;
return;
}
t= top ;
tt = top->next;
while(tt!= NULL)
{
tt =tt->next;
if(tt!= NULL)
{
t=t->next;
tt=tt->next;
}
}
*firstlist =top;
*secondlist =t->next;
t->next = NULL;
}


void mergeSort( struct Node **top)
{
struct Node *firstlist , *secondlist;
if(*top == NULL || (*top)->next == NULL) return ;
spilter(*top , &firstlist , &secondlist);
mergeSort(&firstlist);
mergeSort(&secondlist);
*top = merge(firstlist , secondlist);

}



int main ()
{
char m;
int num;
start = NULL;
while(1)
{
printf("Enter the number :");
scanf("%d" , &num);
fflush(stdin);
addToCollection(num);
printf("Add More (Y/N):");
m= getchar();
fflush(stdin);
if(m!= 'Y' && m!= 'y') break;

}
mergeSort(&start);
printline();
return 0;
}





