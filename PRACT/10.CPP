// Distance Conversion Problem using friend functions.
#include<iostream.h>
#include<conio.h>
class DB;
class DM
 {
 int meter,centimeter;
 public:
  DM(){}
  DM(int m,int c)   {meter=m;centimeter=c;}
  void Set(int m,int c)   {meter=m;centimeter=c;}
  void getlength()
   {
   cout << "Meter value : ";cin >> meter;
   cout << "Centimeter value : ";cin >> centimeter;
   }
  void Print()
   {   cout << meter << "m," << centimeter << "cm";   }
  DM friend addDM(DM,DB);
  DB friend addDB(DB,DM);
 };
class DB
 {
 int feet,inches;
 public:
  DB(){}
  DB(int f,int i)  {feet=f;inches=i;}
  void Set(int f,int i)   {feet=f;inches=i;}
  int centimetervalue()
   {   return (feet*12+inches)*2.5;   }
  void getlength()
   {
   cout << "Feet value : ";cin >> feet;
   cout << "Inches value : ";cin >> inches;
   }
  void Print()
   {   cout << feet << "f," << inches << "in";   }
  DB friend addDB(DB,DM);
  DM friend addDM(DM,DB);
 };
DM addDM(DM dmc,DB dbc)
 {
 DM dmsum;
 int total=dmc.meter*100+dmc.centimeter+((dbc.feet*12+dbc.inches)*2.5);
 dmsum.meter=total/100;dmsum.centimeter=total-total/100*100;
 return dmsum;
 }
DB addDB(DB dbc,DM dmc)
 {
 DB dbsum;
 int total=dbc.feet*12+dbc.inches+((dmc.meter*100+dmc.centimeter)*0.4);
 dbsum.feet=total/12;dbsum.inches=total-(total/12)*12;
 return dbsum;
 }
void main()
{
 clrscr();
 DM dm1,dmsum;
 DB db1,dbsum;
 dm1.getlength();
 db1.getlength();
 dmsum=addDM(dm1,db1);
 dbsum=addDB(db1,dm1);
 cout << "Sum in Meters & Centimeters = ";
 dmsum.Print();
 cout << '\n';
 cout << "Sum in Feet & Inches = ";
 dbsum.Print();
 getch();
}
