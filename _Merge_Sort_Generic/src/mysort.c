#include<mysort.h>
#include<string.h>
#include<stdlib.h>
#include<myutils.h>
#include<mystack.h>

void MergeSort( void  *x, int (*p2f)(void * , void *) , int es, int lowerbound , int upperbound, int *successful , int *error )
{
struct LBUB
{
int lb, ub;
};
int isSuccessful , errorNumber;
struct LBUB lbub;
int a,b;
Stack stack1;
Stack stack2;
int mid;
if(successful) *successful = FAILED;
if(error) *error =0;
initStack(&stack1 , sizeof(struct LBUB) , &isSuccessful , &errorNumber);
initStack(&stack2 , sizeof(struct LBUB) , &isSuccessful , &errorNumber);
lbub.lb = lowerbound;
lbub.ub = upperbound;
Push( &stack1 , (void*)&lbub, &isSuccessful , &errorNumber);
if(!isSuccessful)
{
*error = errorNumber;
clearStack(&stack1 , &isSuccessful , &errorNumber);
clearStack(&stack2 , &isSuccessful , &errorNumber);
return;
}


while(!isEmpty(&stack1, &isSuccessful , &errorNumber))
{
Pop(&stack1 , (void*)&lbub ,&isSuccessful , &errorNumber);
Push( &stack2 , (void*)&lbub, &isSuccessful , &errorNumber);
if(!isSuccessful)
{
*error = errorNumber;
clearStack(&stack1 , &isSuccessful , &errorNumber);
clearStack(&stack2 , &isSuccessful , &errorNumber);
return;
}

a= lbub.lb;
b= lbub.ub;
mid = (a+b)/2;
if(a< mid)
{
lbub.lb =a;
lbub.ub = mid;
Push( &stack1 , (void*)&lbub, &isSuccessful , &errorNumber);
if(!isSuccessful)
{
*error = errorNumber;
clearStack(&stack1 , &isSuccessful , &errorNumber);
clearStack(&stack2 , &isSuccessful , &errorNumber);
return;
}
}
if(mid+1 < b)
{
lbub.lb = mid+1;
lbub.ub = b;
Push( &stack1 , (void*)&lbub , &isSuccessful , &errorNumber);
if(!isSuccessful)
{
*error = errorNumber;
clearStack(&stack1 , &isSuccessful , &errorNumber);
clearStack(&stack2 , &isSuccessful , &errorNumber);
return;
}
}
}

while(!isEmpty(&stack2 , &isSuccessful , &errorNumber))
{
Pop(&stack2 ,(void*)&lbub , &isSuccessful , &errorNumber);
a = lbub.lb;
b = lbub.ub;
mid =(a+b)/2;
Merge(x,p2f,es,a,mid,mid+1, b , &isSuccessful , &errorNumber);
if(!isSuccessful)
{
*error = errorNumber;
clearStack(&stack1 , &isSuccessful , &errorNumber);
clearStack(&stack2 , &isSuccessful , &errorNumber);
return;
}
}
if(successful ) *successful = SUCCESSFUL;
}

