#include<stdio.h>
int main ()
{
int x[10],y,z,num,size,diff,lb,ub;
lb=0;
ub=9;
for(y=0; y<=9; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d" , &x[y]);
}
size = (ub - lb) +1;
diff =size/2;
while(diff >= 1)
{
y =lb + diff;
while(y<= ub)
{
num =x[y];
z = y - diff;
while(z >= 0  && x[z] > num)
{
x[z+diff] = x[z];
z =z-diff;
}
x[z+diff] = num;
y =y + diff;
}
diff = diff/2;
}

for(y=0; y<=9; y++)
{
printf("%d\n" , x[y]);
}

return 0;
}