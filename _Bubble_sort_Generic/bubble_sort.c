#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Bubble_Sort(void *ptr , int cs , int es , int (*p2f)(void *, void *))
{
int e,f,m,w;
void *a, *b, *c;
c = (void *)malloc(es);
m  = cs -2;
while(m >= 0)
{
e=0;
f=1;
while(e<= m)
{
a = ptr + (f *es);
b = ptr + (e *es);
w = p2f(a,b);
if(w < 0)
{
memcpy(c , (const void *)a , es);
memcpy(a, (const void *)b ,es);
memcpy(b , (const void *)c , es);
}
e++;
f++;
}
m--;
}
free(c);
}


//This comparator function takes two arguments. Then compares them and get the relative order between them.

int my_Comparator(void *left , void *right)
{
int *i, *j;
i = (int *) left;
j = (int *) right;
return (*i) - (*j);
}


// MAIN FUNCTION 

int main ()
{
int *x , req, y;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);
if(req <= 0)
{
printf(" INVALID REQUIREMENT");
return 0;
}
x = (int *)malloc(sizeof(int)*req);
if(x== NULL)
{
printf(" UNABLE TO ALLOCATE MEMORY FOR %d NUMBER \n " , req);
return 0;
}
for( int y=0; y<req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
Bubble_Sort( x , req, sizeof(int) , my_Comparator);

for(int y=0; y<req; y++)
{
printf(" %d\n" , x[y]);
}
free(x);
return 0;
}