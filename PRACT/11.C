/* Number of palindromes in a sentece */
#include<string.h>
int Pal(char[]);
main()
{
char s[100],w[20];
int i,c=0,count=0;
printf("Sentence : ");
scanf("%[^\n]",s);
for (i=0;i<=strlen(s);i++)
 if (s[i]!=' ')
  w[c++]=s[i];
 else
  {
  w[c]='\0';c=0;
  if (Pal(w))
   count++;
  }
if (Pal(w))
 count++;
printf("No: of Palindromes = %d",count);
}

int Pal(char a[])
{
int i;
for (i=0;i<strlen(a);i++)
 if (a[i]!=a[strlen(a)-i-1])
  return 0;
return 1;
}