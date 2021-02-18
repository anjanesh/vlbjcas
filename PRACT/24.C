/* Date Convertor */
#include<string.h>
char* inttostring(int); /* Converts an integer to string and returns a pointer containing the string */
main()
{
int dd,mm,yy;
int flag=0,leap;
char date[50]="";
char t;
char month[][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
printf("Enter date in dd/mm/yyyy format : ");
do
 {
  flag=0;
  printf("DD : ");scanf("%d",&dd);
  if (dd<1 || dd>31)
   flag=1;
 } while (flag);
strcpy(date,inttostring(dd));
t=date[strlen(date)-1];
switch(date[strlen(date)-1])
 {
 case 1 :
 if (dd==11) strcat(date,"th ");
 else strcat(date,"st ");
 break;
 case 2 :
 if (dd==12) strcat(date,"th ");
 else strcat(date,"nd ");
 break;
 case 3 :
 if (dd==13) strcat(date,"th ");
 else strcat(date,"rd ");
 break;
 default: strcat(date,"th ");break;
 }
do
 {
  flag=0;
  printf("MM : ");scanf("%d",&mm);
  if (mm<1 || mm>12) flag=1;
  if (dd==31 && (mm==2 || mm==4 || mm==6 || mm==9 || mm==11)) flag=1;
  if (mm==2 && dd>30) flag=1;
 } while (flag);
strcat(date,month[mm-1]);
strcat(date,", ");
do
 {
 flag=0;
 printf("YYYY : ");scanf("%d",&yy);
 leap=!(yy%4)?1:0;
 if (yy%100==0) leap=0;
 if (yy%400==0) leap=1;
 if (mm==2 && dd==29 && leap==0)
  flag=1;
} while (flag);
strcat(date,inttostring(yy));
printf("%s",date);
}
char* inttostring(int d)
{
int cd=d,rem,count=0;
char*dt;
do { count++;} while((cd/=10)!=0);
dt=(char*)malloc((count+1)*sizeof(char));
cd=d;
dt[count]='\0';
do { rem=cd%10;dt[--count]=rem+48; } while ((cd/=10)!=0);
return dt;
}