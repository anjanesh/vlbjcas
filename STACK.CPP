 // Stack
#include<iostream.h>
#include<conio.h>
const MAX=100;
class Stack
 {
 int top;
 int st[MAX];
 public:
  void Push(int n)
   { st[top++]=n; }
  int Pop()
   { return st[top--]; }
  void Show();
 };
void Stack::Show()
 {
 for (int i=0;i<top;i++)
  cout << st[i] << '\t';
 cout << '\n';
 }
void main()
{
clrscr();
Stack s1;
s1.Push(10);
s1.Push(12);
s1.Push(34);
s1.Push(45);
s1.Show();
s1.Pop();
s1.Show();
s1.Pop();
s1.Show();
getch();
}