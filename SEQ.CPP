#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n;
cout << "Enter n : ";cin >> n;
int allsum=0,evensum=0,oddsum=0,squaresum=0;
for (int i=1;i<=n;i++)
 {
 allsum+=i;
 squaresum+=(i*i);
 if (!(i%2))
  evensum+=i;
 else
  oddsum+=i;
 }
cout << "Sum of all no:s upto " << n << " = " << allsum << '\n';
cout << "Sum of all even no:s upto " << n << " = " << evensum << '\n';
cout << "Sum of all odd no:s upto "<< n << " = " << oddsum << '\n';
cout << "Sum of all squared no:s upto " << n << " = " << squaresum << '\n';
getch();
}