#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Linear_Sort (void *ptr , int cs , int es , int(*p2f)(void *, void *))
{
int e,f, oep, iep, w;
void *a, *b ,*c;
c= (void *)malloc(es);
oep = cs-2;
iep = cs-1;
for(e=0; e<=oep; e++)
{
for(f= e+1; f<=iep; f++)
{
 a = ptr +( f *  es);
 b = ptr +( e * es);   
 w = p2f(a,b);
if(w<0)
{
memcpy(c , (const void*)a , es);
memcpy(a , (const void*)b , es);
memcpy(b , (const void*)c , es);
} 
}
}
free(c);
}

// This comparator function takes two arguments. Then compares them and get the relative order between them.

int my_Comparator(void *left ,void *right)
{
int *p2num1 , *p2num2;
p2num1 = (int*)left;
p2num2 = (int*)right;
return  (*p2num1) - (*p2num2);
}
 
// MAIN FUNCTION
 
int main ()
{
int *x, req , y;
printf(" ENTER THE REQUIREMENT :");
scanf("%d", &req);
if(req <= 0)
{
printf(" INVALID REQUIREMENT ");
return 0;
}
x= (int *)malloc(sizeof(int)*req);
for(y=0; y<req; y++)
{
printf("ENTER THE NUMBER :");
scanf("%d", &x[y]);
}
Linear_Sort( x, req , sizeof(int) , my_Comparator);
for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}
free(x);
return 0;
}





