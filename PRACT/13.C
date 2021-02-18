/* Emulation of BASIC's LEFT$, RIGHT$, MID$ */
#include<string.h>
char* left(const char*,int);
char* right(const char*,int);
char* mid(const char*,int,int);
main()
{
char *s=(char*)malloc(100*sizeof(char));
int ls,rs,start,ms;
printf("Enter a string : ");
scanf("%[^\n]",s);
printf("How many characters to left ? ");
scanf("%d",&ls);
printf("Left$(\"%s\",%d) = \"%s\"\n",s,ls,left(s,ls));
printf("How many characters to right ? ");
scanf("%d",&rs);
printf("Right$(\"%s\",%d) = \"%s\"\n",s,rs,right(s,rs));
printf("Starting from position no: ? ");
scanf("%d",&start);
printf("How many characters in middle ? ");
scanf("%d",&ms);
printf("Mid$(\"%s\",%d,%d) = \"%s\"",s,start,ms,mid(s,start,ms));
}

char* left(const char*s,int a)
{
char *leftdollar=(char*)malloc(a*sizeof(char));
int i;
for (i=0;i<a;i++)
 *(leftdollar+i)=*(s+i);
*(leftdollar+i)='\0';
return leftdollar;
}

char* right(const char*s,int a)
{
char *rightdollar=(char*)malloc(a*sizeof(char));
int i;
for (i=0;i<a;i++)
 *(rightdollar+a-i-1)=*(s+strlen(s)-i-1);
*(rightdollar+i)='\0';
return rightdollar;
}

char* mid(const char*s,int a,int b)
{
char *midollar=(char*)malloc(b*sizeof(char));
int i;
for (i=a-1;i<a-1+b;i++)
 *(midollar+i-a+1)=*(s+i);
*(midollar+i-a+1)='\0';
return midollar;
}