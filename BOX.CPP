#include<iostream.h>
#include"box.h"
void main()
{
clrscr();
gotoxy(5,4);cout<<"12345678901234567890123456789012345678901234567890\n";
cout << "   1\n";
cout << "   2\n";
cout << "   3\n";
cout << "   4\n";
cout << "   5\n";
cout << "   6\n";
cout << "   7\n";
cout << "   8\n";
cout << "   9\n";
cout << "  10\n";
cout << "  11\n";
cout << "  12\n";
cout << "  13\n";
cout << "  14\n";
cout << "  15\n";
cout << "  16\n";
cout << "  17\n";
cout << "  18\n";
cout << "  19\n";
cout << "  20";
gotoxy(5,5);cout << "*";
Box a(5,5,30,15,1,2,SINGLE);
a.SetCaption("Anjanesh",14,4,RIGHT);
getch();
a.GetBack();
a.Expand();
getch();
a.Erase();
getch();
}