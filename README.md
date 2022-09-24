# DOCUMENTATION


## Overview

here you get to know about `library` of  Generic Sorting Algorithms , which is built in `c` programming language.


Programmers frequently need to sort elements from a database into a collection, array, or map. In `Java` , we can implement whatever sorting algorithm we want with any type. Using the `Comparable interface` and `compareTo()` method, we can sort using alphabetical order, String length, reverse alphabetical order, or numbers. The 
Comparator interface allows us to do the same but in a more flexible way.



`C++` You can sort a vector of custom objects using the `C++ STL` function `std::sort`. The sort function has an overloaded form that takes as arguments first, last, comparator. The first and last are iterators to first and last elements of the container. The ` comparator ` is a predicate function that can be used to tell how to sort the container. 

* [Generic Merge Sort](#generic-merge-sort)  
   * [ Recursion Merge Sort](#recursion-merge-sort-)

* [Generic Quick Sort](#generic-quick-sort)  
   * [Multiple Stack Quick Sort](#multi-stack-quick-sort)
   * [ Recursion Quick Sort](#recursion-quick-sort-)

* [Generic Bubble Sort ](#generic-bubble-sort) 
* [Generic Insertion Sort ](#generic-insertion-sort) 
* [Generic Selection Sort ](#generic-selection-sort) 
* [Generic Linear Sort ](#generic-linear-sort) 
* [Generic Radix Sort ](#generic-radix-sort) 

 
* [ External Sort](#external-sort)  
* [ External Sort Linked List ](#external-sort-linked-list)  


 
* [ Heap Sort ](#heap-sort) 
* [ PanCake Sort ](#pancake-sort) 
* [ Counting Sort ](#counting-sort) 
* [ Shell Sort ](#shell-sort) 
* [ Pigeon Hole Sort ](#pigeon-hole-sort) 
* [ Gnome Sort ](#gnome-sort) 
* [ Stooge Sort ](#stooge-sort) 
* [ Odd Even Sort ](#odd-even-sort) 
* [ CockTail Shaker Sort ](#cocktail-shaker-sort) 
* [ Binary Insertion Sort ](#binary-insertion-sort) 
* [ Address Calculation Sort ](#address-calculation-sort) 


    




## Generic Merge Sort  
***
### Description of Merge Sort :

* To `create` Flag
   ```c
   #define SUCCESSFUL 1
   #define FAILED 0

* To `create`  Errors
   ```c
   #define NO_ERRORS 0  
   #define NULL_VALUE 1
   #define ELEM_SIZE_ZERO 2
   #define MEM_ALLOC_ERROR 3
   #define STACK_EMPTY  4


* To `create` Init Stack Function
   ```c
   void  initStack( Stack *stack , int elementsize , int *successful , int *error)
   {
   if(successful !=NULL) *successful = FAILED;
   if(error) *error = 0;
   if(stack == NULL)
   {
   if(error) *error  =1;
   return;
   }
   if(elementsize <= 0)
   {
   if(error) *error  = 2;
   return;
   }
   stack->top = NULL;
   stack->elementsize = elementsize;
   stack->size = 0;
   if(successful) *successful  = SUCCESSFUL;
   }

* To `create` Push Function
   ```c
   void Push(Stack *stack , void *ptr , int *successful , int *error )
   {
   StackNode *node;
   if(successful) *successful = FAILED;
   if(error) *error = 0;
   if(stack== NULL) 
   {
   *error  =1;
   return;
   }
   node = (StackNode *)malloc(sizeof(StackNode));
   if(node == NULL)
   {
   if(error) *error = 3;
   return;
   }
   if(ptr!= NULL)
   {
   node->ptr = (void *)malloc(stack->elementsize);
   if(node->ptr==NULL)
   {
   free(node);  
   if(error) *error = 3;
   return;
   }
   memcpy(node->ptr , (const void *)ptr , stack->elementsize );
   }
   else
   {
   node->ptr = ptr;
   }
   node->next = stack->top;
   stack->top = node;
   stack->size++;
   if(successful) *successful = SUCCESSFUL;
   }

* To `create` Pop Function
   ```c
   void Pop(Stack *stack , void *ptr , int *successful , int *error)
   {
   int j;
   StackNode *node;
   if(successful) *successful = FAILED;
   if(error) *error = 0;
   if(stack== NULL || ptr== NULL)
   {
   if(error) *error =1;
   return;
   }
   if(stack->top == NULL)
   {
   if(error) *error =4;
   return;
   }
   if(stack->top->ptr == NULL) 
   {
   for(j=0; j< stack->elementsize ; j++)
   {
   *((char*)(ptr+j)) = (char)0;
   }
   }
   else
   {
   memcpy(ptr , (const void *)stack->top->ptr , stack->elementsize);
   }
   node = stack->top;
   stack->top = stack->top->next;
   if(node->ptr!= NULL) free(node->ptr);
   free(node);
   stack->size--;
   if(successful) *successful = SUCCESSFUL;
   }

* To `create` IsEmpty Function
   ```c
   int isEmpty(Stack *stack , int *successful , int *error )
   {
   if(successful) *successful = FAILED;
   if(error) *error = 0;
   if(stack== NULL) 
   {
   if(error) *error = 1;
   return 1;
   }
   if(successful) *successful = SUCCESSFUL;
   if(stack->size == 0) return 1;
   return 0;
   }

* To `create` Clear Stack Function
   ```c
   void clearStack( Stack *stack , int *successful , int *error) 
   {
   StackNode *node;
   if(successful) *successful = FAILED;
   if(error) *error = 0;
   if(stack== NULL) 
   {
   *error = 1;
   return;
   }
   while(stack->top!= NULL)
   {
   node = stack->top;
   stack->top = stack->top->next;
   if(node->ptr != NULL) free(node->ptr);
   free(node); 
   }
   stack->size = 0;
   if(successful) *successful = SUCCESSFUL;
   }







   
* To `create` Merge Function
   ```c
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



* To `create` Merge Sort Function
   ```c
   void MergeSort( void  *x, int (*p2f)(void * , void *) , int es, int lowerbound , int upperbound, int *successful , int *error )
   {
   struct LBUB 
   {
   int lb, ub;
   };
   int isSuccessful , errorNumber; 
   struct LBUB lbub;
   int a,b;
   Stack stack1;
   Stack stack2;
   int mid;
   if(successful) *successful = FAILED;
   if(error) *error =0;
   initStack(&stack1 , sizeof(struct LBUB) , &isSuccessful , &errorNumber);
   initStack(&stack2 , sizeof(struct LBUB) , &isSuccessful , &errorNumber);
   lbub.lb = lowerbound;
   lbub.ub = upperbound;
   Push( &stack1 , (void*)&lbub, &isSuccessful , &errorNumber);
   if(!isSuccessful)
   {
   *error = errorNumber;
   clearStack(&stack1 , &isSuccessful , &errorNumber);
   clearStack(&stack2 , &isSuccessful , &errorNumber);
   return;
   }


   while(!isEmpty(&stack1, &isSuccessful , &errorNumber))
   {
   Pop(&stack1 , (void*)&lbub ,&isSuccessful , &errorNumber);
   Push( &stack2 , (void*)&lbub, &isSuccessful , &errorNumber);
   if(!isSuccessful)
   {
   *error = errorNumber;
   clearStack(&stack1 , &isSuccessful , &errorNumber);
   clearStack(&stack2 , &isSuccessful , &errorNumber);
   return;
   }
   a= lbub.lb;
   b= lbub.ub;
   mid = (a+b)/2;
   if(a< mid)
   {
   lbub.lb =a;
   lbub.ub = mid;
   Push( &stack1 , (void*)&lbub, &isSuccessful , &errorNumber);
   if(!isSuccessful)
   {
   *error = errorNumber;
   clearStack(&stack1 , &isSuccessful , &errorNumber);
   clearStack(&stack2 , &isSuccessful , &errorNumber);
   return;
   }
   }
   if(mid+1 < b)
   {
   lbub.lb = mid+1;
   lbub.ub = b;
   Push( &stack1 , (void*)&lbub , &isSuccessful , &errorNumber);
   if(!isSuccessful)
   {
   *error = errorNumber;
   clearStack(&stack1 , &isSuccessful , &errorNumber);
   clearStack(&stack2 , &isSuccessful , &errorNumber);
   return;
   }
   }
   }
   while(!isEmpty(&stack2 , &isSuccessful , &errorNumber))
   {
   Pop(&stack2 ,(void*)&lbub , &isSuccessful , &errorNumber);
   a = lbub.lb;
   b = lbub.ub;
   mid =(a+b)/2;
   Merge(x,p2f,es,a,mid,mid+1, b , &isSuccessful , &errorNumber);
   if(!isSuccessful)
   {
   *error = errorNumber;
   clearStack(&stack1 , &isSuccessful , &errorNumber);
   clearStack(&stack2 , &isSuccessful , &errorNumber);
   return; 
   } 
   }     
   if(successful ) *successful = SUCCESSFUL;
   }


* To `create` Comparator Function
   ```c
   This comparator function takes two arguments. Then compares them and get the relative order between them. 
   int intComparator( void *left , void *right)
   {
   return (*((int *)left)) - (*((int*)right)); 
   }



* To `create` Main Function
   ```c
   // MAIN FUNCTION
   int main ()
   {
   int *x, y ,req;
   int isSuccessful , errorNumber;
   printf("Enter requirment :");
   scanf("%d" , &req);
   if(req <= 0)
   {
   printf("invalid requirement\n");
   return 0;
   }
   x =(int*)malloc(sizeof(int)*req);
   if(x== NULL)
   {
   printf("unable to allocate memory \n");
   return 0;
   }
   for(y=0; y<req; y++)
   {
   printf("Enter the number :");
   scanf("%d" , &x[y]);
   }
   MergeSort( (void*)x, intComparator ,  sizeof(int), 0, req-1, &isSuccessful , &errorNumber);
   for( y=0; y<req; y++)
   {
   printf("%d\n" , x[y]);
   }
   free(x);
   return 0;
   }

  

### Recursion Merge Sort :
  
* To `create` Merge Function
   ```c
   void Merge( int *x , int lb , int mid , int ub )
   {
   int i1,i2,i3, tmpsize, lb1,lb2, lb3, ub1,ub2,ub3;
   int *tmp;
   tmpsize = (ub - lb)+1;
   tmp = (int *)malloc(sizeof(int)*tmpsize);
   lb1 = lb;
   ub1 = mid;
   lb2 = mid+1;
   ub2 = ub;

   lb3 = 0;
   ub3 = tmpsize-1;
   i1= lb1;
   i2 = lb2;
   i3 = lb3;

   while(i1 <= ub1   && i2 <= ub2)
   {
   if(x[i1]< x[i2])
   {
   tmp[i3] = x[i1];
   i1++;
   }
   else
   {
   tmp[i3] = x[i2];
   i2++;
   }
   i3++;
   }
   while(i1 <= ub1)
   {
   tmp[i3] = x[i1];
   i1++;
   i3++;
   }
   while(i2 <= ub2)
   {
   tmp[i3] = x[i2];
   i2++;
   i3++;
   }
   i1= lb1;
   i3 =0;
   while( i1 <= ub2)
   {
   x[i1] = tmp[i3];
   i1++;
   i3++;
   }
   free(tmp);
   }


* To `create` Merge Sort Function
   ```c
   void Merge_Sort( int *x , int low , int high )
   {
   int mid;  
   if(low < high)
   { 
   mid = (low + high)/2;
   Merge_Sort(x , low , mid);
   Merge_Sort(x, mid +1 , high);
   Merge(x , low , mid , high);
   }
   }

* To `create` Main Function
   ```c
   int main ()
   {
   int x[10],y;
   for(y=0; y<=9; y++)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   }
   Merge_Sort(x , 0, 9 );
   for(y=0; y<= 9; y++) 
   { 
   printf("%d\n" , x[y]);
   }
   return 0;
   }
   ```










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






## Generic Insertion Sort  
***
### Description of Insertion Sort  :

* To `create` InsertionSortFunction
   ```c
   void Insertion_Sort(void *x , int lb, int ub , int es , int (*p2f)(void * , void*))
   {
   int y,j;
   void *block;
   block =(void*)malloc(es);
   y=lb + 1;
   while(y<=ub)
   {
   memcpy(block , (void*)(x+ (y*es)) , es);
   j= y-1;
   while(j>= lb && p2f(x+(j*es) , block)> 0)
   {
   memcpy( x+((j+1) *es) , (const void *)(x+(j*es)) , es);
   j--;
   }
   memcpy(x+ ((j+1) *es ) ,(const void*) block , es);
   y++;
   }
   free(block);
   }


* To `create` ComparatorFunction
   ```c
   This comparator function takes two arguments. Then compares them and get the relative order between them. 
   
   int My_Comparator(void *left , void *right)
   {
   int *a, *b;
   a = (int*)left;
   b= (int*) right;
   return (*a) - (*b);
   }


* To `create` Main Function
   ```c
   int main ()
   {
   int  *x ,req,y , num , start , end;
   printf(" ENTER THE REQUIREMENT :");
   scanf("%d" ,&req);
   if(req <0)
   {
   printf("INVALID REQUIREMENT");
   return 0;
   }
   printf(" ENTER START POINT :");
   scanf("%d", &start);
   if(start <0 || start >= req)
   {
   printf("INVALID REQUIREMENT\n");
   }
   printf("ENTER END POINT:");
   scanf("%d" , &end);
   if(end< 0  || end > req)
   {
   printf("INVALID REQUIREMENT ");

   }
   x= (int*)malloc(sizeof(int)*req);
   if(x==NULL)
   {
   printf(" UNABLE TO ALLOCATE MEMORY \n");
   return 0;
   }

   y=0;
   while(y<req)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   y++;
   }
   Insertion_Sort(x, start,end ,  sizeof(int) ,  My_Comparator);
   y=0;
   while(y<req)
   {
   printf("%d\n", x[y]);
   y++;
   }
   free(x);
   return 0;
   }


## Generic Selection Sort  
***
### Description of Selection Sort  :

* To `create` SelectionSortFunction
   ```c
   void Selection_Sort(void *ptr , int cs , int es , int (*p2f)(void* , void*))
   {
   int y,e,f,g,m,oep,iep,w; 
   void *a,*b,*c;
   c =(void*)malloc(es);
   oep = cs-2;
   iep = cs-1;
   e=0;
   while(e<= oep)
   {
   m=e;
   f= e+1;
   while(f<=iep)
   {
   a = ptr+( f*es);
   b = ptr +( m*es);
   w = p2f(a,b);
   if(w<0)
   {
   m=f;
   }
   f++;
   }
   a= ptr+(e*es);
   b = ptr+(m*es);
   memcpy(c , (const void*)a, es);
   memcpy(a, (const void*)b,  es);
   memcpy(b, (const void*)c ,es);
   e++;
   }
   free(c);
   }



* To `create` ComparatorFunction
   ```c
   This comparator function takes two arguments. Then compares them and get the relative order between them. 
   
   int My_Comparator(void *left , void *right)
   {
   int *a, *b;
   a = (int*)left;
   b= (int*) right;
   return (*a) - (*b);
   }


* To `create` Main Function
   ```c
   // MAIN FUNCTION

   int main ()
   {
   int *x,y,req;
   printf("ENTER THE REQUIREMENT :");
   scanf("%d" , &req);
   if(req <0)
   {
   printf("INVALID REQUIREMENT\n");
   return 0;
   }
   x =(int *)malloc(sizeof(int)*req);
   if(x== NULL)
   {
   printf("UNABLE TO ALLOCATE MEMORY");
   return 0;
   }
   y=0; 
   while(y<req)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   y++;
   }
   Selection_Sort(x, req, sizeof(int) , My_Comparator);
   y=0;
   while(y<req)
   {
   printf("%d\n", x[y]);
   y++;
   }
   free(x);
   return 0;
   }


## Generic Linear Sort  
***
### Description of Linear Sort  :

* To `create` LinearSortFunction
   ```c
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
  
* To `create` ComparatorFunction
   ```c
   This comparator function takes two arguments. Then compares them and get the relative order between them. 
   
   int My_Comparator(void *left , void *right)
   {
   int *a, *b;
   a = (int*)left;
   b= (int*) right;
   return (*a) - (*b);
   }


* To `create` Main Function
   ```c
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

## Generic radix Sort  
***
### Description of Radix Sort  :

* To `create` Queue
   ```c
  typedef struct _queue_node
  {
  int num;
  struct _queue_node *next;
  }QueueNode;

  typedef struct _queue
  {
  QueueNode *start;
  QueueNode *end;
  int size;
  }Queue;

  void  InitQueue(Queue *queue)
  {
  queue->start = NULL;
  queue->end =NULL;
  queue->size= 0;
  }

  int isQueueEmpty(Queue *queue)
  {
  return queue->size==0;
  }


  void AddToQueue(Queue *queue , int num)
  {
  QueueNode *t;
  t = (QueueNode *)malloc(sizeof(QueueNode));
  t->num = num;
  t->next = NULL;
  if(queue->start== NULL)
  {
  queue->start = t;
  queue->end = t;
  }
  else
  {
  queue->end->next =t;
  queue->end =t;
  }
  queue->size++;
  }

  int RemoveFromQueue(Queue *queue) 
  {
  int num;
  QueueNode *t;
  num = queue->start->num;
  t= queue->start;
  queue->start = queue->start->next;
  free(t);
  queue->size--;
  return num;
  }

  void ClearQueue(Queue *queue)
  {
  QueueNode *t;
  while(queue->start!=NULL)
  {
  t= queue->start;
  queue->start = queue->start->next;
  queue->size--;
  free(t);
  }
  queue->end = NULL;
  queue->size =0;
  }


* To `create` Main Function
   ```c
   // MAIN FUNCTION
   int main ()
   {
   int x[10], y,e,f,i,num,largest,dc,k;
   Queue queue[10];

   for(int i=0; i<=9; i++) InitQueue(&queue[i]);
   for(y=0; y<=9;y++)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   }
   largest= x[0];
   for(y=1; y<=9; y++)
   {
   if(x[y] > largest ) largest = x[y]; 
   }
   dc= 1;
   num =largest;
   while(num >9)
   {
   num = num/10;
   dc++;
   }
   e=10;
   k=1;
   f=1;
   while(k<=dc)
   {
   y=0;
   while(y<=9) 
   {
   num= x[y];
   i = (num %e)/f;
   AddToQueue(&queue[i] , num);
   y++;
   }
   i=0;
   y=0;
   while(y<=9)
   {
   while(!isQueueEmpty(&queue[y]))
   {
   num = RemoveFromQueue(&queue[y]);
   x[i] = num++;
   i++;
   }
   y++;
   }
   e= e*10;
   f= f*10;
   k++;
   }

   for(y=0; y<=9; y++)
   {
   printf("%d\n" , x[y]);
   }
   return 0;
   }  



##  Heap Sort  
***
### Description of Heap Sort  :

* To `create` Heap Function
   ```c
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

* To `create` Main Function
   ```c
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


##  PanCake Sort  
***
### Description of PanCake Sort  :

* To `create` Pancake Sort Function
   ```c
   void Pancake_Sort( int *x , int lb , int ub)
   {
   int y,size, e,f,g,largest;
   size = ub-lb +1;
   while(size > 0)
   {
   largest = lb;
   for(y=0; y<size; y++)
   {
   if(x[largest] < x[y])
   {
   largest = y;
   }
   }

   if(largest == (size-1))
   {
   size--;
   continue;
   }
   e= lb;
   f =largest;
   while(e <=f )
   {
   g= x[e];
   x[e] = x[f];
   x[f] = g;
   e++;
   f--;
   }
   e= lb;
   f= size-1;
   while(e<=f)
   {
   g= x[e];
   x[e] = x[f];
   x[f] = g;
   e++;
   f--;
   }
   size--;
   }
   }

* To `create` Main Function
   ```c
   int main ()
   {
   int  *x , req,y;
   printf("ENTER THE REQUIREMENT :");
   scanf("%d" , &req);
   if(req < 0)
   {
   printf("INVALID REQUIREMENT \n");
   return 0;
   }

   x= (int *)malloc(sizeof(int)*req);
   if(x== NULL)
   {
   printf("UNABLE TO ALLOCATE MEMORY %d  NUMBERS" , req);
   return 0;
   }

   for(y=0; y<req; y++)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   }
   Pancake_Sort(x , 0 , req-1);

   for(y=0; y<req; y++)
   {
   printf("%d\n" , x[y]);
   }

   return 0;
   }


##  Counting Sort  
***
### Description of Counting Sort  :

   * To `create` Main Function
     ```c
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
     printf("UNABLE TO ALLOCATE MEMEORY  %d  NUMBERS       \n" , size);
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


##  Shell Sort  
***
### Description of Shell Sort  :
   
   * To `create` Main Function
      ```c
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


##  External Sort  
***
### Description of External Sort  :

   
* To `Generate Random Number` Function
   ```c
   void GenerateRandomNumberString(char *name , int size)
   {
   int r1, r2, i;
   i=0;
   while(i < size)
   {
   r1 = rand()% 26;
   r2 = rand()%2;
   if(r2== 0)
   {
   name[i] = (char)(r1 + 65);
   }
   else
   {
   name[i] = (char)(r1 + 97);
   }
   i++;
   }
   name[i] = '\0';
   } 

   int countlines( char *filename)
   {
   FILE *f;
   char a[21];
   int line= 0;
   f= fopen(filename , "r");
   while(1)
   {
   fgets(a ,21, f);
   if(feof(f)) break;
   line++;
   }
   fclose(f);
   return line;
   }
 
* To `Create`  Merge Function
   ```c
   void Merge(char *leftfile , char *rightfile , char *mergeto)
   { 
   int leftpos;
   int rightpos;
   FILE *f1, *f2 , *f3;
   char left[21] , right[21];
   int leftnum , rightnum;
   f1 = fopen(leftfile , "r");
   if(f1 == NULL)
   { 
   f1= fopen(leftfile , "w");
   fclose(f1);
   f1 = fopen(leftfile , "r");
   }
   f2 = fopen(rightfile , "r");
   if(f2== NULL) 
   {
   f2 = fopen(rightfile , "w");
   fclose(f2);
   f2 = fopen(rightfile , "r");
   }
   f3 = fopen(mergeto , "w");
   while(1)
   {
   leftpos = ftell(f1);
   fgets(left , 21, f1);
   if(feof(f1)) break;

   rightpos = ftell(f2);
   fgets(right , 21, f2);
   if(feof(f2))    
   { 
   fputs(left , f3);
   break;
   }
   left[strlen(left) -1] = '\0';
   right[strlen(right)-1] = '\0';
   leftnum = atoi(left);
   rightnum = atoi(right);

   if(leftnum < rightnum)
   {
   fputs(left , f3);
   fputs("\n", f3);
   fseek(f2 , rightpos , 0); 
   }
   else
   {
   fputs(right, f3);
   fputs("\n" , f3);
   fseek( f1 , leftpos , 0);
   }
    
   while(1)
   {
   if(feof(f1)) break;
   fgets(left ,21, f1);
   if(feof(f1)) break;
   fputs(left , f3);
   }
   while(1)
   {
   if(feof(f2)) break;
   fgets(right , 21, f2);
   if(feof(f2)) break;
   fputs(right , f3);
   }
   fclose(f1);
   fclose(f2);
   fclose(f3);
   }

* To `Create`  Merge Sort Function
   ```c
   void MergeSort( char *filename , int NumberofLines)
   {
   FILE *left , *right , *file;
   char leftfile[51] , rightfile[51];
   int x;
   char a[21];
   int leftnumberoflines , rightnumberoflines;  
   if(NumberofLines <= 1) return ;
   leftnumberoflines = NumberofLines / 2;
   rightnumberoflines = NumberofLines - leftnumberoflines;
   file = fopen(filename , "r");
   GenerateRandomNumberString(leftfile ,50);
   left = fopen(leftfile , "w");
   x= 1;
   while(x <= leftnumberoflines)
   {
   fgets(a ,21, file);
   fputs(a , left );
   x++;
   }
   fclose(left);
   GenerateRandomNumberString(rightfile ,50);
   right = fopen( rightfile , "w");
   x= 1;
   while(x<= rightnumberoflines)
   {
   fgets(a, 21, file);
   fputs(a, right);
   x++;
   }
   fclose(right);
   fclose(file);
   MergeSort(leftfile , leftnumberoflines);
   MergeSort(rightfile , rightnumberoflines);
   Merge(leftfile  , rightfile , filename);
   }
   

* To `create` Main Function
   ```c
   int main ()
   {
   int lines;
   srand(time (NULL));
   lines = countlines("datafile.ddd");
   printf("%d\n", lines);
   MergeSort("datafile.ddd" , lines);
   return 0;
   }


##   External Sort Linked List 
***
### Description of External Sort  :

   
* To `Create` Add Collection Function
   ```c
   struct Node 
   {
   int num;
   struct Node *next;
   };
   struct Node *start;
   void addToCollection(int num)
   {
   struct Node *t;
   t= (struct Node *)malloc(sizeof(struct Node));
   t->num = num;
   t->next =start;
   start = t;
   }
   // PRINT LINE
   void printline()
   {
   struct Node *t;
   for(t=start; t; t=t->next)
   {
   printf("%d\n" , t->num);
   }
   }  
   

* To `Create` Merge Function
   ```c
   sruct Node *merge(struct Node *firstlist , struct Node *secondlist)
   {
   struct Node *left , *right , *end , *newlist;
   if(firstlist == NULL || secondlist== NULL) return NULL;
   if(firstlist== NULL) return secondlist;
   if(secondlist== NULL) return firstlist;
   newlist = NULL;
   left = firstlist;
   right = secondlist;
   while(left && right)
   {
   if(left->num < right->num)
   {
   if(newlist == NULL) newlist = left;
   else end->next = left;
   end = left;
   left =left->next;
   }
   else
   {
   if(newlist== NULL) newlist = right;
   else end->next = right;
   end = right;
   right = right->next; 
   }
   end->next = NULL;
   }
   if(left) end->next = left;
   if(right) end->next = right;
   return newlist;
   }

* To `Create` Spilter Function
   ```c
   void spilter(struct Node *top , struct Node **firstlist , struct Node **secondlist)
   {
   struct Node *t , *tt;
   if(top == NULL) 
   {
   *firstlist = NULL;
   *secondlist= NULL;
   return;
   }
   if(top->next == NULL) 
   {
   *firstlist = top ;
   *secondlist = NULL;
   return;
   }
   t= top ;
   tt = top->next;
   while(tt!= NULL)
   {
   tt =tt->next;
   if(tt!= NULL)
   {
   t=t->next;
   tt=tt->next;
   }
   }
   *firstlist =top;
   *secondlist =t->next;
   t->next = NULL;
   }

* To `Create` MergeSort Function
   ```c
   void mergeSort( struct Node **top)
   {
   struct Node *firstlist , *secondlist;
   if(*top == NULL || (*top)->next == NULL) return ;
   spilter(*top , &firstlist , &secondlist);
   mergeSort(&firstlist);
   mergeSort(&secondlist);
   *top = merge(firstlist , secondlist);
   }

* To `Create` Main Function
   ```c
   int main ()
   {
   char m;
   int num;
   start = NULL;
   while(1)
   {
   printf("Enter the number :");
   scanf("%d" , &num);
   fflush(stdin);
   addToCollection(num);
   printf("Add More (Y/N):");
   m= getchar();
   fflush(stdin);
   if(m!= 'Y' && m!= 'y') break;
   }
   mergeSort(&start);
   printline();
   return 0;
   }



##  Pigeon Hole Sort  
***
### Description of Pigeon Hole Sort  :

   
* To `Create` Insert Function
   ```c
   struct node
   {
   int data;
   struct node *next;
   };
   struct node **nodeList;
   void Insert( int data  , int index)
   {
   struct node *temp , *t;
   temp = (struct node *)malloc(sizeof(struct node)); 
   temp->data = data;
   if(nodeList[index] == NULL || data < nodeList[index]->data)
   {
   temp->next = nodeList[index];
   nodeList[index] = temp;
   return;
   }
   else
   {
   t = nodeList[index];
   while(t->next!= NULL && t->next->data < data)
   {
   t = t->next;
   }
   temp->next = t->next;
   t->next = temp;
   }
   }

* To `Create` Pigeon Hole Function
   ```c
   void Pigeon_Hole_Sort( int *x , int lb , int ub)
   {
   int y,largest , smallest , index , i , range , size;
   size = ub-lb +1;
   largest = x[0];
   smallest = x[0];
   for(y= lb+1; y<size; y++)
   {
   if(largest < x[y]) largest = x[y];
   if(smallest > x[y] ) smallest = x[y];
   }
   range = largest - smallest + 1;
   nodeList = (struct node **)malloc(sizeof(struct node *)*range);

   for(y=0; y<range; y++)
   {
   nodeList[y] = NULL;
   }
   for(y=lb; y<size; y++)
   {
   index = x[y] - smallest;
   Insert( x[y] , index); 
   }

   i=0;
   for(y=0; y<range; y++)
   {
   while(nodeList[y] != NULL)
   {
   x[i] = nodeList[y]->data;
   nodeList[y]  = nodeList[y]->next;
   i++;
   }
   }
   free(nodeList);
   }

* To `Create` Main Function
   ```c
   int main ()
   {
   int *x , y , req;

   printf("ENTER THE REQUIREMENT :");
   scanf("%d" , &req);
   if(req < 0)
   {
   printf("INVALID REQUIRMENT\n");
   return 0;
   }

   x = (int *)malloc(sizeof(int)*req);
   if(x== NULL)
   {  
   printf("UNABLE TO ALLOCATE MEMORY \n");
   return 0;
   }

   for(y=0; y< req; y++)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   }
   Pigeon_Hole_Sort( x , 0, req-1);

   for(y=0; y<req; y++)
   {
   printf("%d\n" , x[y]);
   }
   return 0;
   }


##  Gnome Sort  
***
### Description of Gnome Sort  :

   
* To `Create` Gnome Sort Function
   ```c
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


   
* To `Create` Main Function
   ```c
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


##  Stooge Sort  
***
### Description of Stooge Sort  :

   
* To `Create` Stooge Function
   ```c
   void Stooge_Sort( int *x , int lb , int ub)
   {
   int y, size, i ,g;
   size = ub-lb +1;
   if(lb >= ub) return;
   if(x[lb] > x[ub])
   {
   g= x[lb];
   x[lb] = x[ub];
   x[ub] = g;
   }
   if(size > 2)
   {
   i = size /3;
   Stooge_Sort(x , lb , ub - i);
   Stooge_Sort(x , lb +  i , ub);
   Stooge_Sort( x, lb , ub - i);
   }
   }


* To `Create` Main Function
   ```c
   int main ()
   {
   int *x , y , req;
   printf("ENTER THE REQUIREMENT :");
   scanf("%d" , &req);
   if(req < 0)
   { 
   printf("INVALID REQUIREMENT");
   return 0;
   }
   x = (int*)malloc(sizeof(int)*req);
   if(x== NULL)
   {
   printf("UNABLE TO ALLOCATE MEMEORY \n");
   return 0;
   }

   for(y=0; y<req; y++)
   {
   printf("ENTER THE NUMBER :");
   scanf("%d" , &x[y]);
   }
   Stooge_Sort(x , 0 , req -1);

   for(y=0; y<req; y++)
   {
   printf("%d\n" , x[y]);
   }
   return 0;
   }


##  Odd Even Sort  
***
### Description of Odd Even Sort  :

   
* To `Create` Main Function
   ```c
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



##  CockTail Shaker Sort  
***
### Description of CockTail Shaker Sort  :

   
* To `Create` CockTail Shaker Function
   ```c
   void CocktailShakersort( int *x , int lb , int ub)
   { 
   int i,y,size,g , swap;
   size = ub- lb + 1;
   swap =1;
   while(swap)
   {
   swap = 0;
   for( i = lb; i<=(size - 2); i++ )
   {
   if(x[i+1] < x[i])
   {
   g = x[i+1];
   x[i+1] = x[i];
   x[i] = g;
   swap =1;
   }
   }
   if(swap == 0) break;
   swap =0;
   ub--;
   for(i = ub -1 ; i>= lb; i--)
   {
   if(x[i+1] < x[i])
   {
   g = x[i+1];
   x[i+1] = x[i];
   x[i] = g;
   swap =1;
   }
   }
   lb++;
   }
   }


* To `Create` Main Function
   ```c
   int main ()
   {
   int *x, req, y;

   printf("ENTER THE REQUIREMENT :");
   scanf("%d" , &req);
   if(req < 0)
   {
   printf(" INVALID REQUIREMENT \n");
   return 0;
   }
   x = (int *)malloc(sizeof(int)*req);
   if(x == NULL)
   {
   printf(" UNABLE TO ALLOCATE MEMORY\n");
   return 0;
   }

   for(y=0; y<req; y++)
   {
   printf("ENTER THE NUMBER :"); 
   scanf("%d" , &x[y]);
   }
   CocktailShakersort(x , 0 , req - 1);

   for(y=0; y<req; y++)
   {
   printf("%d\n" , x[y]);
   }
   return 0;
   }




##  Binary Insertion Sort  
***
### Description of Binary Insertion Sort  :

   
* To `Create` Binary Insertion Function
   ```c
   void Binary_Insertion_Sort( int *x , int lb , int ub)
   {
   int mid , num, z , size ,y , si , ei;
   size = ub - lb +1;
   for(y= lb+1; y<size; y++)
   {
   num = x[y];
   z = y-1;
   si = lb;
   ei = z;
   while(si <= ei)
   {
   mid = si + ((ei - si)/2);
   if(num == x[mid])
   {
   si = mid;
   break;
   }
   if( num  < x[mid]) 
   {
   ei = mid -1;
   }
   else
   {
   si  = mid +1;
   }
   }
   while( z >= si)
   {
   x[z+1] = x[z];
   z--;
   }
   x[z+1] = num;
   }
   }



* To `Create` Main Function
   ```c
   int main ()
   {
   int y,req , *x;
   printf("ENTER THE REQUIREMENT :");
   scanf("%d" , &req);
   if(req < 0 )
   {
   printf("INVALID REQUIRMENT \n");
   return 0;
   }
   x = ( int *)malloc(sizeof(int)*req);
   if(x== NULL)
   {
   printf("UNABLE TO ALLOCATE MEMORY\n");
   return 0;
   }

   for(y=0; y<req; y++)
   {
   printf("ENTER THE NUMBER : ");
   scanf("%d" , &x[y]);
   }

   Binary_Insertion_Sort( x , 0 , req -1);

   for(y=0; y<req; y++) 
   { 
   printf("%d\n" , x[y]);
   }
   return 0;
   }

##  Address Calculation Sort  
***
### Description of  Address Calculation Sort  :

   
* To `Create` Hash Function
   ```c
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

* To `Create` Insert Into Buckets Function
   ```c
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

* To `Create` Address Calculation Function
   ```c
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

* To `Create` Main Function
   ```c
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
