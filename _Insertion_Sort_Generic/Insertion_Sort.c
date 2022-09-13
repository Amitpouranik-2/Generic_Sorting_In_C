#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Insertion_Sort(void *x , int lb, int ub , int es , int (*p2f)(void * , void*))
{
int y,j;
void *block;
block =(void*)malloc(es);
y=lb + 1;
while(y<=ub)
{
memcpy(block , (void*)(x+ (y*es)) , es);
j= y-1;
while(j>= lb && p2f(x+(j*es) , block)> 0)
{
memcpy( x+((j+1) *es) , (const void *)(x+(j*es)) , es);
j--;
}
memcpy(x+ ((j+1) *es ) ,(const void*) block , es);
y++;
}
free(block);
}

int My_Comparator(void *left , void *right)
{
int *a, *b;
a = (int*)left;
b= (int*) right;
return (*a) - (*b);
}

int main ()
{
int  *x ,req,y , num , start , end;
printf(" ENTER THE REQUIREMENT :");
scanf("%d" ,&req);
if(req <0)
{
printf("INVALID REQUIREMENT");
return 0;
}
printf(" ENTER START POINT :");
scanf("%d", &start);
if(start <0 || start >= req)
{
printf("INVALID REQUIREMENT\n");
}
printf("ENTER END POINT:");
scanf("%d" , &end);
if(end< 0  || end > req)
{
printf("INVALID REQUIREMENT ");

}
x= (int*)malloc(sizeof(int)*req);
if(x==NULL)
{
printf(" UNABLE TO ALLOCATE MEMORY \n");
return 0;
}

y=0;
while(y<req)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
y++;
}

Insertion_Sort(x, start,end ,  sizeof(int) ,  My_Comparator);
y=0;
while(y<req)
{
printf("%d\n", x[y]);
y++;
}
free(x);
return 0;
}

