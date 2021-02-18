// Area & Perimiter
#include<iostream.h>
#include<conio.h>
class shape
 {
 protected:
 double side1,side2;
 public:
 void get_data();
 virtual double area()
  { }
 };

class triangle:public shape
 {
 public :
  double area();
 };

class rectangle:public shape
 {
 public:
  double area();
 };
void main()
{
clrscr();
rectangle r1;
triangle t1;
cout << "Rectangle parameters :\n";r1.get_data();
cout << "Triangle parameters :\n";t1.get_data();
cout << "Rectangle Area = " << r1.area() << '\n';
cout << "Triangle Area = " << t1.area();
getch();
}

void shape::get_data()
{
cout << "Enter Side 1 : ";cin >> side1;
cout << "Enter Side 2 : ";cin >> side2;
}

double triangle::area()
 {
 return 0.5 * side1 * side2;
 }

double rectangle::area()
 {
 return side1 * side2;
 }
