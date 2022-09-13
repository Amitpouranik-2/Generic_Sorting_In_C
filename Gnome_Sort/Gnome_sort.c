#include<stdio.h>
#include<stdlib.h>

void Gnome_Sort(int *x , int lb , int ub)
{
int j,g;
j=lb;
while(j<= ub)
{
if(j== lb) j++;

if(x[j] < x[j-1])
{
g = x[j];
x[j] = x[j-1];
x[j-1] = g;
j--;
}
else
{
j++;
}
}
}


int main ()
{
int *x, req, y;

printf("ENTER THE REQUIREMENT :");
scanf("%d" , &req);
if(req < 0)
{
printf(" INVALID REQUIREMENT\n");
return 0;
}

x = (int *)malloc(sizeof(int)*req);

if(x== NULL)
{
printf("UNABLE TO ALLOCATE MEMORY\n");
return 0;
}

for(y=0; y<req; y++)
{
printf(" ENTER THE NUMBER : ");
scanf("%d" , &x[y]);
}

Gnome_Sort(x, 0 , req-1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}


free(x);

return 0;

}