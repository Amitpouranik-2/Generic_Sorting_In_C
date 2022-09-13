#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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


int main ()
{
int lines;
srand(time (NULL));
lines = countlines("datafile.ddd");
printf("%d\n", lines);
MergeSort("datafile.ddd" , lines);
return 0;
}







