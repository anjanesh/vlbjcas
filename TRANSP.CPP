//Transpose of a Matrix
#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int Matrix[100][100], Transpose[100][100];
int j;
int Rows,Cols;
cout << "No:of Rows ? ";
cin >> Rows;
cout << "No:of Columns ? ";
cin >> Cols;
for (int i=0;i<Rows;i++)
 for (j=0;j<Cols;j++)
  {
  cout << "Element: " << i+1 << ":" << j+1 << "=";
  cin >> Matrix[i][j];
  }
for (i=0;i<Cols;i++)
 for (j=0;j<Rows;j++)
  Transpose[i][j]=Matrix[j][i];
cout << "Original Matrix :\n";
for (i=0;i<Rows;i++)
 {
 for (j=0;j<Cols;j++)
  cout << Matrix[i][j] << '\t';
 cout << '\n';
 }
cout << "Transposed Matrix :\n";
for (i=0;i<Cols;i++)
 {
 for (j=0;j<Rows;j++)
  cout << Transpose[i][j] << '\t';
 cout << '\n';
 }
getch();
}