// VLBJCAS afterlogin page (welcome)
#include"vlbjcas1.h"
#include"mystring.h"
#include<fstream.h>
#include<ctype.h>
int check();
void main(int argc,char*argv[])
{
char login[30]="",lgn[30];
if (argv[1]==NULL)
 {
 cout << "Enter your login name : ";
 cin >> lgn;
 }
else
 strcpy(lgn,argv[1]);
for (int i=0;i<strlen(lgn);i++)
 lgn[i]=tolower(lgn[i]);
if (!(strcmp(left(lgn,4),"01cs")==0 || strcmp(lgn,"sathish")==0)) exit(0);
strcpy(login,"f:\\login\\tc3login.exe VLB_JCAS1\\");
strcat(login,lgn);
system(login);
int loginerror = system("dir *.*/s > files.vlb");
if (loginerror==-1) exit(0); // When LoginID or Password goes wrong.

strcpy(login,"Welcome back ");

{
ifstream fl("iibsccsc.dat");
char roll[3],name[25];
strcpy(roll,right(lgn,2));
int rollno=(roll[0]-48)*10+(roll[1]-48);
for(int i=1;i<=rollno;i++)
 fl.getline(name,25);
strcat(login,name);
}
_setcursortype(_NOCURSOR);
strcat(login,"     (");strcat(login,lgn);strcat(login,")");
textbackground(0);clrscr();
textcolor(8);
for (i=1;i<106;i++)
 cprintf("VLBJCAS  VLBJCAS   ");
cprintf("VLBJ");
{
Box vlbjcas(5,3,70,20,1,2,DOUBLE);
vlbjcas.SetCaption(" VLB Jannakiammal College of Arts & Science ",14,4,CENTER);
vlbjcas.Expand(0);
}

{
Label vlb(6,5,68,10,15,2);
vlb.AddText(login);
vlb.ShowLabel();
}

{
Label vlb(6,12,68,10,12+128,0);
vlb.AddText("SECURITY WARNING !");;
vlb.ShowLabel();
}

{
Label vlb(6,13,68,10,12,1);
vlb.AddText("Password is for security purpose");
vlb.AddText("Informing password to your friends is strictly prohibited",LEFT);
vlb.AddText("We are not responsible for the files lost due to misuse of passwords",LEFT);
vlb.AddText("In case of any problem please inform the system adminisrtator.",LEFT);
vlb.ShowLabel();
}

{
Label vlb(36,19,8,1,0,7);
vlb.AddText("Ok");
vlb.ShowLabel();
textcolor(0);textbackground(2);
for (int i=36+1;i<36+8+1;i++)
 {gotoxy(i,19+1);putch(223);}
gotoxy(36+8,19);putch(220);
}

{
Label vlb(60,21,13,1,1,2);
vlb.AddText("(c) VLBJCAS");;
vlb.ShowLabel();
}

getch();
textcolor(7);textbackground(0);clrscr();
_setcursortype(_NORMALCURSOR);
}