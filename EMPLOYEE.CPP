// Employee Salary
#include<iostream.h>
#include<conio.h>
class CEmployee
 {
 char eID[10],Name[50];
 unsigned long BasicPay,PF,HRA,CCA,IT,NetSalary;
 public:
 void Input()
  {
   cout << "ID : ";cin >> eID;
   cout << "Name : ";cin >> Name;
   cout << "Basic Pay : "; cin >> BasicPay;
   cout << "HRA : "; cin >> HRA;
   cout << "Provident Fund : "; cin >> PF;
   cout << "CCA : "; cin >> CCA;
   cout << "Income Tax : "; cin >> IT;
  }
 void CalculateSalary()
  {
  if (BasicPay > 5000)
   NetSalary=BasicPay-0.50*PF-0.45*HRA-0.32*CCA-0.6*IT;
  if (BasicPay > 15000)
   NetSalary=BasicPay-0.45*PF-0.35*HRA-0.26*CCA-0.2*IT;
  if (BasicPay > 50000)
   NetSalary=BasicPay-0.40*PF-0.25*HRA-0.21*CCA-0.1*IT;
  }
 void Show()
  {  cout << "ID : "<< eID << "\tName : " << Name << "\tNet Salary : " << NetSalary;  }
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