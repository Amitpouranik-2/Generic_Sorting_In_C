#include<stdio.h>
#include<stdlib.h>


void Binary_Insertion_Sort( int *x , int lb , int ub)
{
int mid , num, z , size ,y , si , ei;

size = ub - lb +1;

for(y= lb+1; y<size; y++)
{
num = x[y];
z = y-1;

si = lb;
ei = z;

while(si <= ei)
{
mid = si + ((ei - si)/2);

if(num == x[mid])
{
si = mid;
break;
}
if( num  < x[mid])
{
ei = mid -1;
}
else
{
si  = mid +1;
}
}


while( z >= si)
{
x[z+1] = x[z];
z--;
}
x[z+1] = num;
}
}









int main ()
{
int y,req , *x;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);

if(req < 0 )
{
printf("INVALID REQUIRMENT \n");
return 0;
}

x = ( int *)malloc(sizeof(int)*req);
if(x== NULL)
{
printf("UNABLE TO ALLOCATE MEMORY\n");
return 0;
}

for(y=0; y<req; y++)
{
printf("ENTER THE NUMBER : ");
scanf("%d" , &x[y]);
}

Binary_Insertion_Sort( x , 0 , req -1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}
return 0;
}