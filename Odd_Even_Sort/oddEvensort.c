#include<stdio.h>
int main ()
{
int x[10] , e,f,g,y,swapCount;

for(y=0; y<=10; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}

while(1)
{
swapCount =0;
e=1; 
f=2;
while(e<=7)
{
if(x[f] < x[e])
{
g = x[e];
x[e] = x[f];
x[f] = g;
swapCount++;
}
e+=2;
f+=2;
}
e=0;
f=1;
while(e<=8)
{
if(x[f] < x[e])
{
g= x[e];
x[e] = x[f];
x[f] = g;
swapCount++;
}
e+=2;
f+=2;
}
if(swapCount == 0) break;
}
for(y=0; y<=10; y++)
{
printf("%d\n" , x[y]);
}
return 0;
}