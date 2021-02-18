#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include"vlbjcas1.h"
class Label
{
private:
char text[25][75];
int c;
public:
Label(){c=0;}
void AddText(char*s)
 { strcpy(text[c++],s); }
void ShowLabel()
 {
 for (int i=0;i<c;i++)
  cout << text[i] << '\n';
 }
};
void main()
{
clrscr();
Label a;
a.AddText("Hello");
a.AddText("12345");
a.AddText("abcde");
a.AddText("xxxxx");
a.AddText("#####");
a.ShowLabel();
getch();
}