#include<stdio.h>
#include<stdlib.h>
void Heap_Sort(  int *x , int lb , int ub)
{
int y,ri,ci,lci,rci,swi,g;
y = lb+1;
while(y<= ub)
{
ci =y;
while(ci > lb)
{
ri = (ci-1)/2;
if(x[ci] > x[ri])
{
g = x[ci];
x[ci] = x[ri];
x[ri] = g;
ci = ri;
}
else
{
break;
}
}
y++;
}
y =ub;
while(y > lb)
{
g= x[lb];
x[lb] = x[y];
x[y] = g;
y--;
ri = lb;
while(ri < y)
{
lci = (ri *2)+ 1;
if(lci > y) break;
rci = lci + 1;
if(rci > y)
{
swi = lci;
}
else
{
if(x[lci] > x[rci])
{
swi = lci;
}
else
{
swi = rci;
}
}
if(x[swi] > x[ri])
{
g = x[swi];
x[swi] = x[ri];
x[ri] = g;
ri = swi;
}
else
{
break;
}
}
}
}


int main ()
{
int *x, y, req;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);
if(req < 0)
{
printf("INVALID REQUIREMENT\n");
return 0;
}
x = (int *)malloc(sizeof(int)*req);
if(x== NULL)
{
printf(" UNABLE TO ALLOCATE MEMORY\n");
return 0;
}

for(y=0; y<=req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
Heap_Sort( x , 0, req);
for(y=0; y<=req; y++)
{
printf("%d\n" , x[y] );
}
return 0;
}



