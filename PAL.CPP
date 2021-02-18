#include<fstream.h>
#include<conio.h>
#include<string.h>
void main()
{
clrscr();
char a[100],b[100];
ifstream f("k:\\bsc\\ibscc\\01cs147\\wordsa.txt");
while (f.eof()!=0)
 {
 f.getline(a,100);
 strcpy(a,b);
 strrev(b);
 if (strcmp(a,b)==0)
  cout << a << '\n';
 }
f.close();
getch();
}