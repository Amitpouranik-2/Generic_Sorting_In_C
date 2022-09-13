#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *next;
};

struct node **buckets;

int HashFunction( int num , int count)
{
int i=1;
while( i< count)
{
num = num/10;
i++;
}
return num;
}

void InsertIntoBuckets( int data  , int Address)
{
struct node *temp, *t;

temp = (struct node *)malloc(sizeof(struct node));
temp->data = data;

if(buckets[Address] == NULL || data < buckets[Address]->data)
{
temp->next = buckets[Address];
buckets[Address] = temp;
return ;
}
else
{
t =buckets[Address];
while(t->next != NULL && t->next->data < data)
{
t= t->next;
}
temp->next = t->next;
t->next = temp;
} 
}


void Address_calculation_sort( int *x , int lb , int ub)
{
int y, size, largest , countOfLargest , num , Address , i;

size = ub-lb+1;

buckets = (struct node **)malloc(sizeof(struct node *)*size);

for(y=lb; y<size; y++)
{
buckets[y] = NULL;
}

largest = x[lb];

for(y=lb+1; y<size; y++)
{
if(largest < x[y])
{
largest = x[y];
}
}

countOfLargest = 1;
num = largest;
while(num > 9)
{
countOfLargest++;
num = num/10;
}

HashFunction( num , countOfLargest);

for(y= lb; y<size; y++)
{
num = x[y];
Address = HashFunction( num , countOfLargest);
InsertIntoBuckets( num , Address);
}

i=0;
for(y=0; y<size; y++ )
{
while(buckets[y]!= NULL)
{
x[i] = buckets[y]->data;
buckets[y] =  buckets[y]->next;
i++;
}
}
free(buckets);
}



int main ()
{
int *x , req, y;

printf("ENTER THE REQUIREMENT  :");
scanf("%d" , &req);

if(req < 0)
{
printf("INVALID REQUIREMENT\n");
return 0;
}
x= (int *)malloc(sizeof(int )*req);
if(x == NULL)
{
printf("UNABLE TO ALLOCATE MEMORY FOR %d NUMBER " , req);
return 0;
}
for(y=0; y<req; y++)
{
printf("ENTER THE NUMBER : ");
scanf("%d"  , &x[y]);
}

Address_calculation_sort(x , 0 , req-1);

for(y=0; y<req; y++)
{
printf("%d\n" , x[y]);
}
free(x);

return 0;
}
