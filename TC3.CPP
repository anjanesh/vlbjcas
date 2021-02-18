#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
void main()
{
clrscr();
_setcursortype(_NOCURSOR);
textcolor(5+128);gotoxy(15,12);cprintf("Yada Arjuna copan - Welcome to the world of computing !");
for (int i=1;i<25;i++)
 {
 gotoxy(i,15);cout << "Arjun";
 gotoxy(60-i,15);cout << "Sandhya";
 delay(100);
 gotoxy(i,15);cout << "     ";
 gotoxy(60-i,15);cout << "       ";
 }
gotoxy(i,15);cout << "Arjun L VES";
gotoxy(i+7,15);textcolor(12+128);cprintf("");textcolor(7);

gotoxy(60-i+2,15);cout << "Sandhya";

cout << "\n\n\t\tHit any key to continue to TurboC\n";
getch();
cout << "\tLoading Turbo C/C++3.0..........................please be patient";
system("t:\\turboc3\\tc3.exe");
system("del tcdef.dsk");
system("del tcdef.dpr");
system("del tcconfig.tc");
system("cls");
system("echo Go home !!!");
_setcursortype(_NORMALCURSOR);
}

