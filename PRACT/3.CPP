// Rectangle <-> Polar Conversion
#include<iostream.h>
#include<conio.h>
#include<math.h>
class rectangle;
class polar
 {
 float radius,angle;
 public:
  polar(){}
  polar(float r,float a) { radius=r;angle=a; }
  void Input();
  rectangle CRect();
  void Show()
   {  cout << "Radius : " << radius << "\tAngle : " << angle << '\n';  }
 };
class rectangle
 {
 float x,y;
 public:
  rectangle(){}
  rectangle(float x1,float y1){x=x1;y=y1;}
  void Input();
  polar CPolar();
  void Show()
   {   cout << "X Coordinate : " << x << "\tY Coordinate : " << y << '\n';  }
 };
void main()
{
 clrscr();
 rectangle r1,r2;
 polar p1,p2;

 cout << "Enter Rectangle Coordinates :\n";
 r1.Input();
 p2=r1.CPolar();
 cout << "Converting to Polar Coordinates :\n";
 p2.Show();

 cout << "Enter Polar Coordinates :\n";
 p1.Input();
 r2=p1.CRect();
 cout << "Converting to Rectangle Coordinates :\n";
 r2.Show();

 getch();
}

rectangle polar::CRect()
 {  return rectangle(radius*cos(angle),radius*sin(angle)); }

polar rectangle::CPolar()
 { return polar(sqrt(x*x+y*y),atan(x/y)); }

void polar::Input()
 {
 cout << "Radius : ";cin >> radius;
 cout << "Angle : ";cin >> angle;
 }

void rectangle::Input()
 {
 cout << "X Coordinate : ";cin >> x;
 cout << "Y Coordinate : ";cin >> y;
 }