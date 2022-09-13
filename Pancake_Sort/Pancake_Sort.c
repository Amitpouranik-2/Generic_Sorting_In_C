#include<stdio.h>
#include<stdlib.h>
void Pancake_Sort( int *x , int lb , int ub)
{
int y,size, e,f,g,largest;
size = ub-lb +1;
while(size > 0)
{
largest = lb;
for(y=0; y<size; y++)
{
if(x[largest] < x[y])
{
largest = y;
}
}

if(largest == (size-1))
{
size--;
continue;
}
e= lb;
f =largest;
while(e <=f )
{
g= x[e];
x[e] = x[f];
x[f] = g;
e++;
f--;
}
e= lb;
f= size-1;
while(e<=f)
{
g= x[e];
x[e] = x[f];
x[f] = g;
e++;
f--;
}
size--;
}
}

int main ()
{

int  *x , req,y;
printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);
if(req < 0)
{
printf("INVALID REQUIREMENT \n");
return 0;
}

x= (int *)malloc(sizeof(int)*req);
if(x== NULL)
{
printf("UNABLE TO ALLOCATE MEMORY %d  NUMBERS" , req);
return 0;
}

for(y=0; y<req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
Pancake_Sort(x , 0 , req-1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}

return 0;
}