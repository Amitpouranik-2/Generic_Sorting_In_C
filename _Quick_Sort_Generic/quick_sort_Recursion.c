#include<stdio.h>

int Find_Partition_Point( int *x , int lb , int ub)
{
int e,f,g;
e =lb;
f =ub;
while(e <f)
{
while(e <ub && x[e] <= x[lb])
{
e++;
}
while( x[f] > x[lb])
{
f--;
}

if(e <f)
{
g = x[e];
x[e] = x[f];
x[f] = g;
}
else
{
g= x[lb];
x[lb] = x[f];
x[f] = g;
}
}
return f;
}

void Quick_Sort(int *x , int lb , int ub)
{
int pp;
if(ub <= lb) return;

pp = Find_Partition_Point( x ,lb, ub);
Quick_Sort( x , lb , pp-1);
Quick_Sort( x , pp+1 , ub);
}


int main()
{
int x[10], y;
for( y=0; y<=9; y++)
{
printf("ENTER THE NUMBER : ");
scanf("%d" , &x[y]);
}
Quick_Sort(x ,0, 9);
for( y=0; y<=9; y++ )
{
printf("%d\n" , x[y]);
}
return 0;
}

