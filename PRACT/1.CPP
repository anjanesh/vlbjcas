// Distance Conversion Problem
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
  int inchvalue()
   { return (meter*100+centimeter)*0.4; }
  void getlength()
   {
   cout << "Meter value : ";cin >> meter;
   cout << "Centimeter value : ";cin >> centimeter;
   }
  void Print()
   {   cout << meter << "m," << centimeter << "cm";   }
  DM add(DM,DB);
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
  DB add(DB,DM);
 };
DM DM::add(DM dmc,DB dbc)
 {
 int total=dmc.meter*100+dmc.centimeter+dbc.centimetervalue();
 meter=total/100;centimeter=total-total/100*100;
 return DM (meter,centimeter);
 }
DB DB::add(DB dbc,DM dmc)
 {
 int total=dbc.feet*12+dbc.inches+dmc.inchvalue();
 feet=total/12;inches=total-(total/12)*12;
 return DB (feet,inches);
 }
void main()
{
 clrscr();
 DM dm1,dmsum;
 DB db1,dbsum;
 dm1.getlength();
 db1.getlength();
 dmsum.add(dm1,db1);
 dbsum.add(db1,dm1);
 cout << "Sum in Meters & Centimeters = ";
 dmsum.Print();
 cout << '\n';
 cout << "Sum in Feet & Inches = ";
 dbsum.Print();
 getch();
}