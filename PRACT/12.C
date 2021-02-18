/* Concordance from a line of input text */
#include<string.h>
main()
{
char s[100],w[20][20],t[20];
int i,j,n=0,c=0,count=1;
printf("Enter the string : ");
scanf("%[^\n]",s);
for (i=0;i<=strlen(s);i++)
 if (s[i]!=' ')
  w[n][c++]=s[i];
 else
  {
  w[n++][c]='\0';c=0;
  }
w[n][c]='\0';
for (i=0;i<=n-1;i++)
 for (j=i+1;j<=n;j++)
  if (strcmp(w[i],w[j])>0)
   {
   strcpy(t,w[i]);
   strcpy(w[i],w[j]);
   strcpy(w[j],t);
   }
for (i=1;i<=n;i++)
 if (strcmp(w[i-1],w[i])!=0)
  {
  printf("%s %d\n",w[i-1],count);
  count=1;
  }
 else
  count++;
printf("%s %d\n",w[n],count);
}