// Command Line Arguments
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
 {
 float result;
 if (strcmp(argv[1],"add")==0) result=atof(argv[2])+atof(argv[3]);
 if (strcmp(argv[1],"sub")==0) result=atof(argv[2])-atof(argv[3]);
 if (strcmp(argv[1],"mul")==0) result=atof(argv[2])*atof(argv[3]);
 if (strcmp(argv[1],"div")==0) result=atof(argv[2])/atof(argv[3]);
 cout << result << '\n';
 }
