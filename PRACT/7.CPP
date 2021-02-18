// String Manupulation
#include<iostream.h>
#include<conio.h>
class string
 {
 char str[1000];
 int length();
 public:
  string(){}
  string(char*);
  void Show();
  int operator == (const string);
  string operator + (const string);
 };
int string::length()
 {
  int l=0,flag=1;
  while (flag)
  {
  if (str[l++]=='\0')
   flag=0;
  }
 return l-1;
 }
int string::operator == (const string cs)
 {
  if (length()!=cs.length()) return 0;
  int flag=0;
  for (int i=0;i<length();i++)
   if (str[i]!=cs.str[i])
    {
    flag=1;break;
    }
  return !flag;
 }
string string::operator + (const string cs)
 {
 int l1=length(),l2=cs.length();
 char*cons=new char[l1+l2+1];
 cons="";
 for (int i=0;i<l1;i++)
  cons[i]=str[i];
 for (i=0;i<l2;i++)
  cons[i+l1]=cs.str[i];
 cons[i+l1]='\0';
 return string(cons);
 }
void main()
{
clrscr();
char str1[100],str2[100];
cout << "Enter string 1 : ";cin >> str1;
cout << "Enter string 2 : ";cin >> str2;
string a(str1),b(str2),c;
if (a==b)
 cout << "same\n";
else
 cout << "different\n";
c=a+b;
cout << "Concatenation of " ;a.Show();
cout << " and ";b.Show();
cout << " = ";c.Show();
getch();
}

void string::Show()
 {
 cout << str;
 }

string::string(char*s)
 {
  int flag=1,len=0;
  while (flag)
  {
  if (s[len++]=='\0')
   flag=0;
  }
 //str=new char[len--+1];
 str[0]='\0';
 for (int i=0;i<len;i++)
  str[i]=s[i];
 str[i]='\0';
 }
