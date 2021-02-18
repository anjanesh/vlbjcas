/* To Compare 2 strings using user defined functions */
#include<string.h>
int compare(char*,char*); /* user-defined strcmp() */
main()
{
char*s1=(char*)malloc(100*sizeof(char));
char*s2=(char*)malloc(100*sizeof(char));
char comparision[3][10]={"smaller","equal","greater"};
printf("String 1:");gets(s1);
printf("String 2:");gets(s2);
printf("%s is %s when compared to %s",s1,comparision[compare(s1,s2)],s2);
}
int compare(char*a,char*b)
/*
returns 0 if a < b
returns 1 if a = b
returns 2 if a > b
*/
{
int l1=strlen(a),l2=strlen(b);
int l=(l1<l2?l1:l2);
int i,flag=0,result;
char c1,c2;
for (i=0;i<l;i++)
 if (a[i]!=b[i])
  {c1=a[i];c2=b[i];flag=1;break;}
if (flag)
 result=(c1>c2?2:0);
else
 result=(l1==l2?1:(l1<l2?0:2));
return result;
}