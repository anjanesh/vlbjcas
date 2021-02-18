#include <conio.h>
#include <dos.h>
#include <string.h>
enum style {SINGLE,DOUBLE,FULL_THICK,CUSTOM};
enum LinearAllignment {LEFT,CENTER,RIGHT};
struct HighlightedWord
 {
 char *hword;
 int Fore, Back;
 Set (char *w,int f=0,int b=7)
  { hword=new char[strlen(w)+1];strcpy(hword,w);Fore=f;Back=b; }
 void PrintWord(int x,int y)
  {
   textcolor(Fore);textbackground(Back);
   gotoxy(x,y);cprintf(hword);
  }
 };

class Box
 {
 private :
 int Xcoor,Ycoor;
 int Length,Width;
 int Fore,Back;
 HighlightedWord Caption;
 LinearAllignment allignment;
 char Edge[6];
 char *Backtext;
 style Linestyle;
 char customchar;
 void fillspace(int,int,int,int);
 void fillborder(int,int,int,int);
 public :
 Box ()
 {
  Xcoor=1;Ycoor=1;Length=78;Width=24;Fore=7;Back=0;Linestyle=SINGLE;
  Caption.Set("Untitled");allignment=0;
  SetEdges();
  }
 Box (int x,int y,int l,int w,int f,int b,style st=SINGLE,char ch='*')
  {
  Xcoor=x;Ycoor=y;Length=l;Width=w;Fore=f;Back=b;Linestyle=st;customchar=ch;
  Caption.Set("Untitled");allignment=0;
  SetEdges();
  }
 void SetAll (int x,int y,int l,int w,int f,int b,char *cap,int f1,int b1,LinearAllignment all=LEFT,style st=SINGLE,char ch='*')
  {
  Xcoor=x;Ycoor=y;Length=l;Width=w;Fore=f;Back=b;Linestyle=st;customchar=ch;
  Caption.Set(cap,f1,b1);allignment=all;
  SetEdges();
  }
 void SetCaption (char *cap, int f,int b,LinearAllignment all=LEFT)
 { Caption.Set(cap,f,b);allignment=all; }
 void SetColor (int f,int b) { Fore=f;Back=b; }
 void SetStyle(style st,char ch='*') { Linestyle=st;customchar=ch;SetEdges(); }
 void SetEdges();
 void Draw();
 void Expand(int);
 void GetBack(){Backtext=new char[(Width+1)*(Length+1)*2];gettext(Xcoor,Ycoor,Xcoor+Length,Ycoor+Width,Backtext);}
 void Erase(){puttext(Xcoor,Ycoor,Xcoor+Length,Ycoor+Width,Backtext);}
 };
void Box::SetEdges()
 {
  switch(Linestyle)
   {
    case SINGLE :
    Edge[0]=196;Edge[1]=179;Edge[2]=218;
    Edge[3]=191;Edge[4]=192;Edge[5]=217;
    break;
    case DOUBLE :
    Edge[0]=205;Edge[1]=186;Edge[2]=201;
    Edge[3]=187;Edge[4]=200;Edge[5]=188;
    break;
    case FULL_THICK :
    for (int i=0;i<6;i++) Edge[i]=219;break;
    case CUSTOM:
    for (i=0;i<6;i++) Edge[i]=customchar;break;
   }
 }

void Box::Draw()
 {
 window(Xcoor,Ycoor,Xcoor+Length,Ycoor+Width);
 textcolor(Fore);textbackground(Back);
 gotoxy(1,1);putch(char(Edge[2]));gotoxy(Length,1);putch(char(Edge[3]));
 gotoxy(1,Width);putch(char(Edge[4]));
 gotoxy(Length,Width);putch(char(Edge[5]));
 for (int i=2;i<Length;i++)
  {
   gotoxy(i,1);putch(char(Edge[0]));
   gotoxy(i,Width);putch(char(Edge[0]));
  }
 for (i=2;i<Width;i++)
  {
   gotoxy(1,i);putch(char(Edge[1]));
   gotoxy(Length,i);putch(char(Edge[1]));
  }
 fillspace(2,2,Length-1,Width-1);
 switch (allignment)
 {
  case LEFT : Caption.PrintWord(2,1);break;
  case CENTER : Caption.PrintWord(Length/2-strlen(Caption.hword)/2,1);break;
  case RIGHT : Caption.PrintWord(Length-strlen(Caption.hword),1);
 }
 window(1,1,80,25);
}

void Box::Expand(int dl=15)
{
 int i;
 int tempXcoor=Xcoor,tempYcoor=Ycoor,tempLength=Length,tempWidth=Width;
 window(tempXcoor,tempYcoor,tempXcoor+tempLength,tempYcoor+tempWidth);
 Xcoor+=Length/2-1;
 Ycoor+=Width/2-1;
 if (Length%2) Length=3; else Length=2;
 if (Width%2) Width=3; else Width=2;

 while (Xcoor>tempXcoor || Ycoor>tempYcoor)
 {
  window(Xcoor,Ycoor,Xcoor+Length,Ycoor+Width);
  textcolor(Fore);textbackground(Back);
  gotoxy(1,1);putch(char(Edge[2]));gotoxy(Length,1);putch(char(Edge[3]));
  gotoxy(1,Width);putch(char(Edge[4]));
  gotoxy(Length,Width);putch(char(Edge[5]));
  for (i=2;i<Length;i++)
   {
    gotoxy(i,1);putch(char(Edge[0]));
    gotoxy(i,Width);putch(char(Edge[0]));
   }
  for (i=2;i<Width;i++)
   {
    gotoxy(1,i);putch(char(Edge[1]));
    gotoxy(Length,i);putch(char(Edge[1]));
   }
 delay(dl);
 fillborder(2,2,Length-1,Width-1);
 if (Xcoor>tempXcoor) {Xcoor--;Length+=2;}
 if (Ycoor>tempYcoor) {Ycoor--;Width+=2;}
 }
window(1,1,80,25);
Xcoor=tempXcoor;Ycoor=tempYcoor;Length=tempLength;Width=tempWidth;
Draw();
}

void Box::fillspace(int x1,int y1,int x2,int y2)
{
int i,j;
for (i=y1;i<=y2;i++)
 for (j=x1;j<=x2;j++)
  {gotoxy(j,i);putch(32);}
}

void Box::fillborder(int x1,int y1,int x2,int y2)
{
int i,j;
if (y1!=y2)
 for (i=y1;i<=y2;i++)
  {
  gotoxy(2,i);putch(32);
  gotoxy(x2,i);putch(32);
  }
if (x1!=x2)
 for (j=x1;j<=x2;j++)
  {
  gotoxy(j,2);putch(32);
  gotoxy(j,y2);putch(32);
  }
}

class Label
{
private:
int xcoor,ycoor;
int height,width;
int forecolor,backcolor;
int allign[25];
char text[25][75];
int countlines;
public:
Label() { countlines=0; }
Label(int x,int y,int w,int h,int fc,int bc)
 { xcoor=x;ycoor=y;height=h;width=w;forecolor=fc;backcolor=bc;countlines=0;}
void AddText(char*s,LinearAllignment all=CENTER)
 {
 strcpy(text[countlines],s);
 allign[countlines++]=all;
 }
void ShowLabel()
 {
 textcolor(forecolor);
 if(backcolor!=-1) textbackground(backcolor);
 int currentx;
 for (int i=0;i<countlines;i++)
  for (int j=xcoor;j<xcoor+width;j++)
   { gotoxy(j,ycoor+i);cprintf(" "); }
 for (i=0;i<countlines;i++)
  {
  switch(allign[i])
   {
   case LEFT:currentx=0;break;
   case CENTER:currentx=width/2-strlen(text[i])/2;break;
   case RIGHT:currentx=width-strlen(text[i]);
   }
  gotoxy(xcoor+currentx,ycoor+i);cprintf(text[i]);
  }
 }
~Label()
 {}
};
