// Arithmetic operation functions
#include<iostream.h>
#include<conio.h>
class Arith
 {
 float a,b,c;
public:
 void get();
 float add();
 float sub();
 float mul();
 float div();
 };

void Arith::get()
 {
 cout << "Enter no:1 ";cin >> a;
 cout << "Enter no:2 ";cin >> b;
 }
float Arith::add()
 { return c=a+b; }
float Arith::sub()
 { return c=a-b; }
float Arith::mul()
 { return c=a*b; }
float Arith::div()
 { return c=a/b; }

void main()
{
clrscr();
Arith a;
a.get();
cout << "Addition of the 2 no:s = " << a.add() << '\n';
cout << "Subtraction of the 2 no:s = " << a.sub() << '\n';;
cout << "Multiplication of the 2 no:s = " << a.mul() << '\n';;
cout << "Division of the 2 no:s = " << a.div() << '\n';;
getch();
}