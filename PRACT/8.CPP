// Employee Salary
#include<iostream.h>
#include<conio.h>
class CEmployee
 {
 char eID[10],Name[50];
 float BasicPay,PF,HRA,DA,NetSalary;
 unsigned int IT;
public:
 void Input()
  {
   cout << "ID : ";cin >> eID;
   cout << "Name : ";cin >> Name;
   cout << "Basic Pay : "; cin >> BasicPay;
  }
 void CalculateSalary()
  {
  if (BasicPay <= 5000)
   { HRA=100.0;DA=0.20*BasicPay;PF=100.0;IT=0;}
  if (BasicPay > 5000)
   { HRA=300.0;DA=0.35*BasicPay;PF=150.0;IT=30;}
  if (BasicPay > 15000)
   { HRA=400.0;DA=0.45*BasicPay;PF=200.0;IT=35;}
  if (BasicPay > 50000)
   { HRA=500.0;DA=0.50*BasicPay;PF=300.0;IT=40;}
  NetSalary=(float(100-IT)/100)*(BasicPay+HRA+DA-PF);
  }
 void Show()
  {
  cout << "ID\tName\tBasic\tHRA\tDA\tPF\tIT\tNet Salary\n";
  cout << eID << '\t' << Name << '\t' << BasicPay << '\t' << HRA << '\t' << DA << '\t' << PF << '\t' << IT << "%" << '\t' << NetSalary;
  }
 };
void main()
{
clrscr();
CEmployee e1;
e1.Input();
e1.CalculateSalary();
e1.Show();
getch();
}
