#include<stdio.h>
#include<stdlib.h>
int main ()
{
int  x[10] , largest , y, size, num , i;
int *tmp;

for(y=0; y<10; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}

largest = x[0];
for(y=0; y<10; y++)
{
if( largest < x[y])
{
largest = x[y];
}
}
size = largest +1;
tmp = (int *)malloc(sizeof(int)*size);
if(tmp == NULL)
{
printf("UNABLE TO ALLOCATE MEMEORY  %d  NUMBERS \n" , size);
return 0;
}
for(y=0; y<size; y++)
{
tmp[y] = 0;
}

for(y=0; y<10; y++)
{
num = x[y];
tmp[num]+=1;
}
i=0;
for(y=0; y<size; y++)
{
num = tmp[y];
while(num)
{
x[i] = y;
i++;
num-=1;
}
}
for(y=0;y<10; y++)
{
printf("%d\n" , x[y]);
}
return 0;
}