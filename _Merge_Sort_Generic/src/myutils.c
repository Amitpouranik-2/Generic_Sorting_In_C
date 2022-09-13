
#include<myutils.h>
#include<string.h>
#include<stdlib.h>
void Merge(void  *x, int (*p2f)(void *, void *) , int es , int lb1 , int ub1, int lb2 , int ub2 , int *successful , int *error)
{
void *tmp;
int i1,i2,i3;

if(successful) *successful = FAILED;
if(error) *error =0;
if(x== NULL || p2f == NULL)
{
if(error) *error =1;
return;
}
if(es <= 0)
{
if(error) *error = 2;
return;
}
int size1,size2,size3;
size1 = (ub1 -lb1) +1;
size2 = (ub2 - lb2) +1;
size3 = size1 + size2;
tmp = (void *)malloc(es*size3);
if(tmp == NULL)
{
if(error) *error = 3;
return;
}
i1= lb1;
i2= lb2;
i3 = 0;
while(i1 <= ub1 && i2<= ub2)
{
if(p2f(x +(i1*es) , x+(i2*es)) < 0)
{
memcpy(tmp+(i3*es) , (const void *)(x+ (i1*es)) , es);
i1++;
}
else
{
memcpy(tmp+(i3*es) , (const void *)(x+ (i2*es)) , es);
i2++;
}
i3++;
}
while( i1 <= ub1)
{
memcpy(tmp+(i3*es) , (const void *)(x+ (i1*es)) , es);
i1++;
i3++;
}
while(i2 <= ub2)
{
memcpy(tmp+(i3*es) , (const void *)(x+ (i2*es)) , es);
i2++;
i3++;
}
i3= 0;
i1 = lb1;
while(i1<= ub1)
{  
memcpy( x +(i1*es) , (const void *)(tmp+ (i3*es)) , es);
i1++;
i3++;
}
i2 =lb2;
while(i2 <= ub2)
{
memcpy(x +(i2*es) , (const void *)(tmp+ (i3*es)) , es);
i2++;
i3++;
}
free(tmp);
if(successful) *successful = SUCCESSFUL;
}
