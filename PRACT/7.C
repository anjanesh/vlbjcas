/* To print a calender for a given month of a year */
#include<conio.h>
int Leap(int); /* returns if a year is leap or not */
void DisplayMonth(int,int,int);
main()
{
int day=3; /* Setting the day of the year to 2002 - Tuesday, the 3rd day starting from Sunday */
int i;
int month, year,nthday=0;/* indicates the no: of days elapsed since Jan 1st */
clrscr();
printf("Enter the Month : ");scanf("%d",&month);
printf("Enter the Year : ");scanf("%d",&year);
if (year > 2002)
 for (i=2003;i<=year;i++)
  {
  day++;
  if (day==8) day=1;
  if (Leap(i-1)) day++;
  if (day==8) day=1;
  }
if (year < 2002)
 for (i=2001;i>=year;i--)
  {
  day--;
  if (!day) day=7;
  if (Leap(i)) day--;
  if (!day) day=7;
  }
for (i=1;i<month;i++)
switch(i)
 {
 case 4:case 6:case 9:case 11: nthday+=30; break;
 case 2: nthday+=28; if (Leap(year)) nthday++; break;
 default: nthday+=31;
 }
day+=nthday%7;
if (day>7) day-=7;
DisplayMonth(day,month,year);
}

int Leap(int lp)
{
int res=0;
if (!(lp%4)) res=1;
if (!(lp%100)) res=0;
if (!(lp%400)) res=1;
return res;
}

void DisplayMonth(int dd,int mm,int yyyy)
{
int i,max;
printf("\n\tSun\tMon\tTue\tWed\tThu\tFri\tSat");
printf("\n\tอออออออออออออออออออออออออออออออออออออออออออออออออออ\n");
switch(mm)
 {
 case 4:case 6:case 9:case 11: max=30; break;
 case 2: max=28; if (Leap(yyyy)) max++; break;
 default: max=31;
 }
for (i=1;i<=dd;i++)
 printf("\t");
for (i=1;i<=max;i++)
 {
 printf("%d\t",i);
 if ((i+dd-1)%7==0)
  printf("\n\t");
 }
}
