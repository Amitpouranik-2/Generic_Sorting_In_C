#include<stdio.h>
#include<stdlib.h>

void CocktailShakersort( int *x , int lb , int ub)
{
int i,y,size,g , swap;
size = ub- lb + 1;

swap =1;
while(swap)
{
swap = 0;
for( i = lb; i<=(size - 2); i++ )
{
if(x[i+1] < x[i])
{
g = x[i+1];
x[i+1] = x[i];
x[i] = g;
swap =1;
}
}

if(swap == 0) break;

swap =0;
ub--;
for(i = ub -1 ; i>= lb; i--)
{
if(x[i+1] < x[i])
{
g = x[i+1];
x[i+1] = x[i];
x[i] = g;
swap =1;
}
}
lb++;
}
}



int main ()
{
int *x, req, y;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);

if(req < 0)
{
printf(" INVALID REQUIREMENT \n");
return 0;
}

x = (int *)malloc(sizeof(int)*req);

if(x == NULL)
{
printf(" UNABLE TO ALLOCATE MEMORY\n");
return 0;
}

for(y=0; y<req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}

CocktailShakersort(x , 0 , req - 1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}
return 0;
}