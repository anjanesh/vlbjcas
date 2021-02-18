// Sum of Rows & Cols of a matrix
#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int Matrix[100][100];
int j;
int Rows,Cols;
cout << "No:of Rows ? ";
cin >> Rows;
cout << "No:of Columns ? ";
cin >> Cols;
for (int i=0;i<Rows;i++)
 for (j=0;j<Cols;j++)
  {
  cout << "Element : " << i+1 << ":" << j+1 << "=";
  cin >> Matrix[i][j];
  Matrix[Rows][j]=0;Matrix[i][Cols]=0;Matrix[Rows][Cols]=0;
  }
for (i=0;i<Rows;i++)
 for (j=0;j<Cols;j++)
  {
  Matrix[i][Cols]+=Matrix[i][j];
  Matrix[Rows][j]+=Matrix[i][j];
  Matrix[Rows][Cols]+=Matrix[i][j];
  }
for (i=0;i<=Rows;i++)
 {
 for (j=0;j<=Cols;j++)
  cout << Matrix[i][j] << '\t';
 cout << '\n';
 }
getch();
}