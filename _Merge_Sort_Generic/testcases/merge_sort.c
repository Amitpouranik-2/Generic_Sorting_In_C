#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<tmsort.h>

int intComparator( void *left , void *right)
{
return (*((int *)left)) - (*((int*)right)); 
}
int main ()
{
int *x, y ,req;
int isSuccessful , errorNumber;
printf("Enter requirment :");
scanf("%d" , &req);
if(req <= 0)
{
printf("invalid requirement\n");
return 0;
}
x =(int*)malloc(sizeof(int)*req);
if(x== NULL)
{
printf("unable to allocate memory \n");
return 0;
}
for(y=0; y<req; y++)
{
printf("Enter the number :");
scanf("%d" , &x[y]);
}
MergeSort( (void*)x, intComparator ,  sizeof(int), 0, req-1, &isSuccessful , &errorNumber);
for( y=0; y<req; y++)
{
printf("%d\n" , x[y]);

}
free(x);
return 0;
}

