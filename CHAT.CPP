#include<iostream.h>
#include<conio.h>
#include<dos.h>
#define PORT1 0x3F8
void main()
{
clrscr();
int c,ch;
outportb(PORT1+1,0);
outportb(PORT1+3,0x80);
outportb(PORT1+0,0x03);
outportb(PORT1+1,0x00);
outportb(PORT1+3,0x03);
outportb(PORT1+2,0xC7);
outportb(PORT1+4,0x0B);
do {
     c=inportb(PORT1+5);
     if (c & 1)
      {
       ch=inportb(PORT1);
       cout << '\n' << ch;
      }
     if (kbhit())
      {
       ch=getche();
       outportb(PORT1,ch);
      }
   } while (ch!=27);
}