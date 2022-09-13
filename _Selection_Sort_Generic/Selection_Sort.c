#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Selection_Sort(void *ptr , int cs , int es , int (*p2f)(void* , void*))
{
int y,e,f,g,m,oep,iep,w;
void *a,*b,*c;
c =(void*)malloc(es);
oep = cs-2;
iep = cs-1;
e=0;
while(e<= oep)
{
m=e;
f= e+1;
while(f<=iep)
{
a = ptr+( f*es);
b = ptr +( m*es);
w = p2f(a,b);
if(w<0)
{
m=f;
}
f++;
}
a= ptr+(e*es);
b = ptr+(m*es);
memcpy(c , (const void*)a, es);
memcpy(a, (const void*)b,  es);
memcpy(b, (const void*)c ,es);
e++;
}
free(c);
}











int My_Comparator(void *left , void  *right)
{
int *a ,*b;
a= (int *)left;
b= (int *)right;
return (*a )- (*b);
}

// MAIN FUNCTION

int main ()
{
int *x,y,req;
printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);
if(req <0)
{
printf("INVALID REQUIREMENT\n");
return 0;
}
x =(int *)malloc(sizeof(int)*req);
if(x== NULL)
{
printf("UNABLE TO ALLOCATE MEMORY");
return 0;
}
y=0;
while(y<req)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
y++;
}
Selection_Sort(x, req, sizeof(int) , My_Comparator);
y=0;
while(y<req)
{
printf("%d\n", x[y]);
y++;
}
free(x);
return 0;
}

