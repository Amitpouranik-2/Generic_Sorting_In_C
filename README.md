# DOCUMENTATION


## Overview

here you get to know about `library` of  Generic Sorting Algorithms , which is built in `c` programming language.


Programmers frequently need to sort elements from a database into a collection, array, or map. In `Java` , we can implement whatever sorting algorithm we want with any type. Using the `Comparable interface` and `compareTo()` method, we can sort using alphabetical order, String length, reverse alphabetical order, or numbers. The 
Comparator interface allows us to do the same but in a more flexible way.



`C++` You can sort a vector of custom objects using the `C++ STL` function `std::sort`. The sort function has an overloaded form that takes as arguments first, last, comparator. The first and last are iterators to first and last elements of the container. The ` comparator ` is a predicate function that can be used to tell how to sort the container. 



* [Generic Quick Sort](#generic-quick-sort)  
   * [Multiple Stack Quick Sort](#multi-stack-quick-sort)
   * [ Recursion Quick Sort](#recursion-quick-sort-)

* [Generic Bubble Sort ](#generic-bubble-sort) 


    
## Generic Quick Sort  
***
### Description of Quick Sort :

* To `create` Push & Pop Function
   ```c
   struct Node
   {
   int lb,ub;
   struct Node *next;
   };
   struct Node *top;

   int isEmpty()
   {
   return top==NULL;
   }

   void push(int lowerbound , int upperbound)
   {
   struct Node *t;
   t= (struct Node *)malloc(sizeof(struct Node));
   t->lb =lowerbound;
   t->ub =upperbound;
   t->next = top;
   top =t;
   }

   void pop(int *lowerbound , int *upperbound)
   {
   struct Node *t;
   *lowerbound = top->lb;
   *upperbound = top->ub;
   t= top;
   top = top->next;
   free(t);
   }
   


* To `create` Comparator Function
   ```c
   This comparator function takes two arguments. Then compares them and get the relative order between them. 
   int My_Comparator( void *left ,void *right)
   {
   int *a, *b;
   a =(int*)left;
   b =(int*)right;
   return (*a) - (*b);
   }
   
* To `create` PartitionPoint Function
   ```c
   int Partition_Point( void  *x , int lb , int ub ,int es , int (*p2f)(void * , void*))
   {
   int e,f;
   void *g;
   g = (void*)malloc(es);
   e =lb;
   f= ub;
   while(e<f)
   {
   while( e<ub && p2f(x+ (e*es), x+(lb*es)) <=0) e++;
   while( p2f(x+(f*es) , x+(lb*es))>0) f--;
   if(e<f)
   {
   memcpy(g ,(const void *)(x+(e*es)),es);
   memcpy(x+(e*es) ,(const void *)(x+ (f*es)) , es);
   memcpy(x+(f*es) , (const void *)g ,es);
   }
   else
   {
   memcpy(g, (const void *)(x+(lb*es)), es);
   memcpy(x+(lb*es) , (const void *)(x+(f*es)) ,es);
   memcpy(x+(f*es), (const void *)g ,es);
   }
   }
   free(g);
   return f;
   }
 
* To `create` Quick Sort Function
  ```c
  void Quick_Sort(void *x ,int lowerbound , int upperbound , int es , int (*p2f)(void * , void *))
  {
  int lb,ub,pp;
  push(lowerbound , upperbound);
  while(!isEmpty())
  {
  pop(&lb ,&ub);
  pp =Partition_Point( x, lb,ub, es ,p2f);
  if(pp+1 < ub) push(pp+1 , ub);
  if(lb <pp-1) push(lb ,pp-1);
  }
  }

* To `create` Main Function
   ```c

   // MAIN FUNCTION

   int main ()
   {
   int *x, req,y;
   top==NULL;

   printf("ENTER THE REQUIREMENT:");
   scanf("%d", &req);
   if(req<= 0)
   {
   printf("INVALID REQUIREMENT");
   return 0;
   }
   x= (int *)malloc(sizeof(int)*req);
   if(x==NULL)
   {
   printf("UNABLE TO ALLOCATE MEMORY");
   return 0; 
   }
   for(y=0; y<req; y++)
   {
   printf(" ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   }
   Quick_Sort(x,0, req-1, sizeof(int), My_Comparator);
   for(y=0; y<req; y++)
   {
   printf("%d\n" ,x[y]);
   }
   return 0;
   }
  
### Multi Stack Quick Sort:  

* To `init` in Stack 
  ```c
  typedef struct _StackNode__
  {
  int data;
  struct _StackNode__ *next;
  }StackNode;

  typedef struct __stack_
  {
  StackNode *top;
  int size;
  } Stack;

  void initStack( Stack *stack)
  {
  stack->top = NULL;
  stack->size = 0;
  }

* To `push` in Stack
  ```c
  void push(Stack *stack , int data)
  {
  StackNode *t;
  t= (StackNode*)malloc(sizeof(StackNode));
  t->data= data;
  t->next = stack->top;
  stack->top = t;
  stack->size++;
  }

* To `pop` in Stack
  ```c
  int pop(Stack *stack)
  {
  int data;
  StackNode *t;
  data = stack->top->data;
  t =stack->top;
  stack->top = stack->top->next;
  stack->size--;
  free(t);
  return data;
  }

* To `isEmpty` in Stack
  ```c
  int isEmpty(Stack *stack)
  {
  return stack->size == 0;
  }

* To `create` Partition Point Function
  ```c
  int Partition_Point( int *x , int lb , int ub)
  {
  int e,f,g;
  e=lb;
  f= ub;
  while(e<f)
  {
  while(e <ub && x[e] <= x[lb]) e++;
  while( x[f] > x[lb]) f--;
  if(e<f)
  {
  g= x[e];
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

* To `create` Quick Sort Function
  ```c
  void Quick_Sort( int *x , int lowerbound , int upperbound)
  {
  Stack lbstack , ubstack;
  int lb,ub, pp;
  initStack(&lbstack);
  initStack(&ubstack);
  push(&lbstack , lowerbound);
  push(&ubstack , upperbound);
  while(!isEmpty(&lbstack))
  {
  lb = pop(&lbstack);
  ub = pop(&ubstack);
  pp = Partition_Point( x,lb,ub);
  if(pp+1 <ub) 
  {
  push(&lbstack , pp+1);
  push(&ubstack , ub);
  }
  if(lb < pp-1)
  {
  push(&lbstack , lb);
  push(&ubstack , pp-1);
  }
  }
  }

* To `create` Main Function
  ```c
   int main ()
  {
  int y,x[10];
  for(y=0; y<=9; y++)
  {
  printf(" ENTER THE NUMBER :");
  scanf("%d" , &x[y]);
  }
  Quick_Sort(x,0,9);
  for(y=0; y<=9 ; y++)
  {
  printf("%d\n", x[y]);
  }
  return 0;
  }

### Recursion Quick Sort :
  
* To `create` PartitionPoint Function
  ```c
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

* To `create` Quick Sort Function
  ```c
  void Quick_Sort(int *x , int lb , int ub)
  {
  int pp;
  if(ub <= lb) return;
  pp = Find_Partition_Point( x ,lb, ub);
  Quick_Sort( x , lb , pp-1);
  Quick_Sort( x , pp+1 , ub);
  }

* To `create` Main Function
  ```c

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

  ```
  
  
## Generic Bubble Sort  
***
### Description of Bubble Sort  :

* To `create` BubbleSortFunction
   ```c
   void Bubble_Sort(void *ptr , int cs , int es , int (*p2f)(void *, void *))
   { 
   int e,f,m,w;
   void *a, *b, *c;
   c = (void *)malloc(es);
   m  = cs -2; 
   while(m >= 0)
   {
   e=0;
   f=1;
   while(e<= m)
   {
   a = ptr + (f *es);
   b = ptr + (e *es);
   w = p2f(a,b);
   if (w < 0)
   {
   memcpy(c , (const void *)a , es);
   memcpy(a, (const void *)b ,es);
   memcpy(b , (const void *)c , es);
   }
   e++;
   f++;
   }
   m--;
   }
   free(c);
   }

* To `create` ComparatorFunction
   ```c
   This comparator function takes two arguments. Then compares them and get the relative order between them. 
   int my_Comparator(void *left , void *right)
   {
   int *i, *j;
   i = (int *) left;
   j = (int *) right;
   return (*i) - (*j);
   }

* To `create` Main Function
   ```c


  
  int main ()
  {
  int *x , req, y;
  printf("ENTER THE REQUIREMENT :");
  scanf("%d" , &req);
  if(req <= 0)
  {
  printf(" INVALID REQUIREMENT");
  return 0;
   } 
  x = (int *)malloc(sizeof(int)*req);
  if(x== NULL)
  {
  printf(" UNABLE TO ALLOCATE MEMORY FOR %d NUMBER \n " , req);
  return 0;
  }
  for( int y=0; y<req; y++)
  {
  printf("ENTER THE NUMBER :");
  scanf("%d" , &x[y]);
  }
  Bubble_Sort( x , req, sizeof(int) ,      my_Comparator);

  for(int y=0; y<req; y++)
  {
  printf(" %d\n" , x[y]);
  }
  free(x);
  return 0;
  }



