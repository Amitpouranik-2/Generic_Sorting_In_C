# DOCUMENTATION


## Overview

here you get to know about `library` of  Generic Sorting Algorithms , which is built in `c` programming language.


Programmers frequently need to sort elements from a database into a collection, array, or map. In `Java` , we can implement whatever sorting algorithm we want with any type. Using the `Comparable interface` and `compareTo()` method, we can sort using alphabetical order, String length, reverse alphabetical order, or numbers. The 
Comparator interface allows us to do the same but in a more flexible way.




`C++` You can sort a vector of custom objects using the `C++ STL` function `std::sort`. The sort function has an overloaded form that takes as arguments first, last, comparator. The first and last are iterators to first and last elements of the container. The ` comparator ` is a predicate function that can be used to tell how to sort the container. 



* [Generic Bubble Sort ](#generic-bubble-sort)  
 


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
  Bubble_Sort( x , req, sizeof(int) , my_Comparator);

  for(int y=0; y<req; y++)
  {
  printf(" %d\n" , x[y]);
  }
  free(x);
  return 0;
  }



