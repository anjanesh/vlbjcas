// Files
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
class Student
 {
 char name[50];
 char roll[10];
 char sex;
 char address[100];
public:
 Student()
  {
  }
 void setDetails();
 void showDetails();
 char* getName(){return name;}
 };
void Student::setDetails()
 {
 cout << "Enter Student Details : \n";
 cout << "Name : ";flushall();gets(name);
 cout << "Roll no : "; cin >> roll;
 cout << "Sex :";cin >> sex;
 cout << "Address : ";gets(address);
 }
void Student::showDetails()
 {
 cout << "Name : " << name << '\n' << "Roll : " << roll << '\n' << "Sex : " << sex << '\n' << "Address : " << address << '\n';
 }
class Studentdb
 {
 char filename[50];
 Student s;
 fstream f;
public:
 Studentdb(){strcpy(filename,"students.dat");}
 Studentdb(char*fl){strcpy(filename,fl);}
 int add();
 int update();
 int create();
 int del();
 void display();
 };
int Studentdb::create()
 {
 f.open(filename,ios::out);
 cout << "File Created!";
 f.close();
 return 1;
 }
int Studentdb::add()
 {
 f.open(filename,ios::app);
 s.setDetails();
 f.write((char*)&s,sizeof(Student));
 f.close();
 return 1;
 }
int Studentdb::update()
 {
 int flag=0;
 char sname[50];
 f.open(filename,ios::out||ios::in);
 cout << "Name : ";flushall();gets(sname);
 while (!f.eof())
  {
  f.read((char*)&s,sizeof(Student));
  if (strcmp(s.getName(),sname)==0)
   {
   flag++;
   f.seekg(f.tellg()-sizeof(Student));
   s.setDetails();
   f.write((char*)&s,sizeof(Student));
   }
  }
 f.close();
 if (flag)
  {cout << "Record(s) updated";return 1;}
 else
  {cout << "No such Name found!";return 0;}
 }
int Studentdb::del()
 {
 int flag=0;
 char sname[50];
 f.open(filename,ios::in);
 fstream ftmp("temp.dat",ios::out);
 cout << "Name : ";flushall();gets(sname);
 while (!f.eof())
  {
  f.read((char*)&s,sizeof(Student));
  if (strcmp(s.getName(),sname)==0) continue;
  ftmp.write((char*)&s,sizeof(Student));
  }
 f.close();ftmp.close();
 remove(filename);rename("temp.dat",filename);
 if (flag)
  {cout << "Record(s) updated";return 1;}
 else
  {cout << "No such Name found!";return 0;}
 }
void Studentdb::display()
 {
 f.open(filename,ios::in);
 while (!f.eof())
  {
  f.read((char*)&s,sizeof(Student));
  s.showDetails();
  }
 f.close();
 }
void main()
 {
 Studentdb sdb1;
 int ch;
 do
  {
  clrscr();
  cout << "Menu\n";
  cout << "====\n";
  cout << "1. Create\n";
  cout << "2. Add\n";
  cout << "3. Update\n";
  cout << "4. Delete\n";
  cout << "5. Display\n";
  cout << "6. Exit\n";
  cin >> ch;
  switch(ch)
   {
   case 1:sdb1.create();break;
   case 2:sdb1.add();break;
   case 3:sdb1.update();break;
   case 4:sdb1.del();break;
   case 5:sdb1.display();break;
   }
  cout << "Hit any key to continue.";getch();
  } while (ch!=6);
 }