/* Searching for the first position of a character after a specified position
   and insertion of a word in a sentence at a specified position. */
#include<string.h>
int pos1st(const char*,char,int);
char* left(const char*,int);
char* right(const char*,int);
char* insert(char*,char*,int);
main()
{
char *s=(char*)malloc(100*sizeof(char));
char *b=(char*)malloc(100*sizeof(char));
int p,pos;
char c;
printf("Enter a sentence : ");
gets(s);
printf("Character to be searched for ? ");
scanf("%c",&c);
printf("Starting from position number ? ");
scanf("%d",&p);
printf("Position of the 1st occurrence of the character '%c' \n starting from the %dth character position = %d\n",c,p,pos1st(s,c,p));
printf("Enter the string to be inserted : ");
flushall();gets(b);
printf("At position no: ? ");scanf("%d",&pos);
s=insert(s,b,pos);
printf("String after insertion : %s",s);
}

int pos1st(const char *s,char c,int a)
{
int i;
for (i=a-1;i<strlen(s);i++)
 if (s[i]==c)
  break;
return i==strlen(s)?0:i+1;
}

char* insert(char *s1,char *s2,int p)
{
char*fs=(char*)malloc((strlen(s1)+strlen(s2)+1)*sizeof(char));
strcpy(fs,left(s1,p-1));
strcat(fs,s2);strcat(fs," ");
strcat(fs,right(s1,strlen(s1)-p+1));
return fs;
}

char *left(const char*s,int a)
{
char *leftdollar=(char*)malloc(a*sizeof(char));
int i;
for (i=0;i<a;i++)
 leftdollar[i]=s[i];
leftdollar[i]='\0';
return leftdollar;
}

char *right(const char*s,int a)
{
char *rightdollar=(char*)malloc(a*sizeof(char));
int i;
for (i=0;i<a;i++)
 rightdollar[a-i-1]=s[strlen(s)-i-1];
rightdollar[i]='\0';
return rightdollar;
}
