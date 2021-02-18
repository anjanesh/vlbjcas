// Sorting using QuickSort method
void quicksort(int[],int,int);
main()
{
int n,i,a[100];
printf("No: of no:s");
scanf("%d",&n);
for (i=0;i<n;i++)
 scanf("%d",&a[i]);
quicksort(a,1,n);
printf("QuickSorted list\n");
for (i=0;i<n;i++)
 printf("%d\t",a[i]);
}
void quicksort(int a[],int m,int n)
{
int i,j,k;
if (m<n)
 {
 i=m;j=n+1;k=a[m];
 while(i<j)
  {
  do i++; while((a[i]<=k && i<=n));
  do j--; while(a[j]>k);
  if (i<j)
   {int t=a[i];a[i]=a[j];a[j]=t;}
  else
   {
   int t=a[m];a[m]=a[j];a[j]=t;
   quicksort(a,m,j-1);
   quicksort(a,j+1,n);
   }
  }
 }
}