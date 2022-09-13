#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main ()
{
char a[15];
int x ,r, j;
FILE *f;
f= fopen("datafile.ddd" ,"w");
srand(time (NULL));
for(j=1; j<=100 ; j++)
{
r=rand();
sprintf(a, "%d\n" , r);
fputs(a ,f);
}
fclose(f);
return 0;
}


