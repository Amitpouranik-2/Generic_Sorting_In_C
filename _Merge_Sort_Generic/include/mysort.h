#ifndef __mysort__
#define __mysort__ 123
#include<myconst.h>
#include<myerror.h>
#include<mystack.h>
#include<myutils.h>
void MergeSort( void *x, int(*p2f)(void * , void *) , int es , int lowerbound , int upperbound , int *successful , int *error);
#endif