// Sorting using HeapSort method
main()
{
int i,j,m,n,a[100],b[100];
printf("No: of no:s");
scanf("%d",&n);
m=n;
for (i=0;i<n;i++)
 scanf("%d",&a[i]);
do
 {
 for(i=m;i>=2;i--)
  {
  j=i/2;
  if (a[i]>a[j])
   {int t=a[i];a[i]=a[j];a[j]=t;}
  }
  b[m]=a[i];a[i]=a[m];m--;
  if (m==1)
   b[m]=a[i];
 } while (m!=1);
printf("HeapSorted list\n");
for (i=0;i<n;i++)
 printf("%d\t",a[i]);
}