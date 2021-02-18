/* Palindrome using recursive function */
#include<string.h>
int Pal(char[],int,int);
main()
{
char s[100],ns[100];
int i,j=0;
printf("Enter a sentence : ");
scanf("%[^\n]",s);
for (i=0;i<strlen(s);i++)
 if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
  ns[j++]=s[i];
ns[j]='\0';
if (Pal(ns,0,strlen(ns)-1))
 printf("Not Palindrome");
else
 printf("Palindrome");
}

int Pal(char s[],int l,int u)
{ return u-l<1?0:(s[l]==s[u])?Pal(s,l+1,u-1):1; }