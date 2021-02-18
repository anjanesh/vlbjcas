#include<iomanip.h>
#include<conio.h>
#include<iostream.h>
ostream &dispstar(ostream &out)
 {out << "x";return out;}
ostream &dispequal(ostream &out)
 {out << "=";return out;}
ostream &set(ostream &out)
 {
 out.precision(1);
 out.setf(ios::showpos);
 out.setf(ios::showpoint);
 out << setw(10);
 return out;
 }
void main()
{
 clrscr();
 int n;
 cout << "Table of : ";
 cin >> n;
 for (int i=1;i<=10;i++)
  cout << set << n << " " << dispstar << " " << i << dispequal << " " << set << n*i << '\n';
}