#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class student
 {
 int roll;
 char name[50];
 int Mark1,Mark2,Mark3;
 float avg;
 public :
  void Input()
   {
   cout << "Roll No : "; cin >> roll;
   flushall();
   cout << "Enter Name : ";gets(name);
   cout << "Mark 1 : "; cin >> Mark1;
   cout << "Mark 2 : "; cin >> Mark2;
   cout << "Mark 3 : "; cin >> Mark3;
   }
  float average()
   {   return avg=float(Mark1+Mark2+Mark3)/3;   }
 };
void main()
{
clrscr();
student s1;
s1.Input();
cout << "Average = " << s1.average();
getch();
}