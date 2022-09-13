#include<stdio.h>
#include<stdlib.h>

void Stooge_Sort( int *x , int lb , int ub)
{
int y, size, i ,g;

size = ub-lb +1;

if(lb >= ub) return;

if(x[lb] > x[ub])
{
g= x[lb];
x[lb] = x[ub];
x[ub] = g;
}
if(size > 2)
{
i = size /3;
Stooge_Sort(x , lb , ub - i);
Stooge_Sort(x , lb +  i , ub);
Stooge_Sort( x, lb , ub - i);
}
}
int main ()
{

int *x , y , req;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);

if(req < 0)
{
printf("INVALID REQUIREMENT");
return 0;
}

x = (int*)malloc(sizeof(int)*req);
if(x== NULL)
{
printf("UNABLE TO ALLOCATE MEMEORY \n");
return 0;
}

for(y=0; y<req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
Stooge_Sort(x , 0 , req -1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}

return 0;
}