#ifndef __tmutils__
#define __tmutils__123
#include<myconst.h>
#include<mymerge.h>
void Merge(void *x, int(*p2f)(void * , void *) , int es , int lb1 , int ub1 , int lb2 , int ub2 , int *successful , int *error);
#endif
