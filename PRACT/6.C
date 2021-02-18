/* Nunmber of days elapsed between 2 dates */
main()
{
int dd[2],mm[2],yy[2],i,j,leap[2];
/* ddmmyy date format is stored in an array for validation of both the dates */
int flag,nthday;
unsigned long elapsedays=0;
for (i=0;i<2;i++)
 {
 printf("\nDate %d (DD/MM/YYYY format)\n",i+1);
 do
  {
   flag=0;
   printf("DD : ");scanf("%d",&dd[i]);
   if (dd[i]<1 || dd[i]>31)
    flag=1;
  } while (flag==1);
 do
  {
   flag=0;
   printf("MM : ");scanf("%d",&mm[i]);
   if (mm[i]<1 || mm[i]>12)
    flag=1;
   if (dd[i]==31 && (mm[i]==2 || mm[i]==4 || mm[i]==6 || mm[i]==9 ||mm[i]==11))
    flag=1;
   if (mm[i]==2 && dd[i]>30)
    flag=1;
  } while (flag);
 do
  {
  flag=0;
  printf("YYYY : ");scanf("%d",&yy[i]);
  // Negativity of year is not checked as a negative year indicates B.C.
  if (yy[i]%4==0) leap[i]=1;
  else leap[i]=0;
  if (yy[i]%100==0) leap[i]=0;
  if (yy[i]%400==0) leap[i]=1;
  if (dd[i]==29 && leap[i]==0)
   flag=1;
  } while (flag==1);
 nthday=0;
 for (j=1;j<mm[i];j++)
  {
  switch(j)
   {
   case 4:case 6:case 9:case 11:
   nthday+=30;
   break;
   case 2:nthday+=28;
   if (leap[i]==1) nthday++;
   break;
   default: nthday+=31;
   }
  }
 nthday+=dd[i];
 elapsedays+=(i==0)?365-nthday:nthday;
 }
elapsedays=elapsedays+(long)(yy[1]-yy[0]-1)*(long)365;
for (i=yy[0];i<yy[1];i++)
 {
  if (yy[i]%4==0) elapsedays++;
  if (yy[i]%100==0) elapsedays--;
  if (yy[i]%400==0) elapsedays++;
 }

printf ("\nNo: of elapsed days = %ld\n", elapsedays);
}