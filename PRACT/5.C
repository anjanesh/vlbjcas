/* Search for a name using Binary Search */
#include<string.h>
#include<conio.h>
main()
{
int n=8,flag=0,i,j;
int l,h,m;
int pos;
char name[50][20];
char sname[20],t[20];
clrscr();
printf("How many names ? ");
scanf("%d",&n);
for (i=0;i<n;i++)
 {
 printf("Name %d : ",i+1);
 scanf("%s",&name[i]);
 }
// Sorting
for (i=0;i<n-1;i++)
 for (j=i+1;j<n;j++)
  if (strcmp(name[i],name[j])>0)
   {
   strcpy(t,name[i]);
   strcpy(name[i],name[j]);
   strcpy(name[j],t);
   }
printf("Name to be searched ? ");
scanf("%s",&sname);
for (i=0;i<n;i++)
 printf("%s\t",name[i]);
l=0;h=n-1;
m=l+(l+h)/2;
while (l<=m)
{
 if (strcmp(sname,name[m])<0)
  h=m;
 else if (strcmp(sname,name[m])>0)
  l=m;
 else
  {flag=1;pos=m;}
 // if (l==m) break;
  m=l+(l+h)/2;
}
printf("\nBinary Search : ");
if (flag==1)
 printf("Name exists at position %d\n",pos+1);
else
 printf("Name not found\n");

for (i=0;i<n;i++)
 if (strcmp(sname,name[i])==0)
  {flag=1;pos=i;}
printf("Linear Search : ");
if (flag==1)
 printf("Name exists at position %d ",pos+1);
else
 printf("Not Found");
}