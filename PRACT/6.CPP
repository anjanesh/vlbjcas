// The Matrix
#include<iostream.h>
#include<conio.h>
const int MAXRows = 10;
const int MAXCols = 10;
class MAT
 {
 int m,n;
 int array[MAXRows][MAXCols];
 public:
  MAT(){}
  MAT(int a,int b)
  {
  m=a;n=b;
  initialize();
  }
  void initialize();
  int cols(){return n;}
  int rows(){return m;}
  MAT operator +(MAT);
  MAT operator -(MAT);
  MAT operator *(MAT);
  MAT operator /(MAT);
  void SetDimension(MAT);
  void Show();
  void Get();
 };
void MAT::SetDimension(MAT mt=MAT(-1,-1))
 {
 if (mt.m==-1 && mt.n==-1)
  {
  cout << "Enter the no: of rows : ";cin >> m;
  cout << "Enter the no: of columns : ";cin >> n;
  }
 else
  {m=mt.m;n=mt.n;}
 initialize();
 }
void MAT::initialize()
 {
 int i,j;
 for (i=0;i<m;i++)
  for (j=0;j<n;j++)
   array[i][j]=0;
 }
void MAT::Get()
 {
 int i,j;
  for (i=0;i<m;i++)
  {
   for (j=0;j<n;j++)
   {
   cout << "Element - " << i << " : " << j << " ";
   cin >> array[i][j];
   }
   cout << '\n';
  }

 }
void MAT::Show()
 {
  int i,j;
  for (i=0;i<m;i++)
  {
   for (j=0;j<n;j++)
    cout << array[i][j] << '\t';
   cout << '\n';
  }
 }
MAT MAT::operator + (MAT matrix)
 {
 MAT res(matrix.m,matrix.n);
 int i,j;
 for (i=0;i<matrix.m;i++)
  for (j=0;j<matrix.n;j++)
   res.array[i][j]=array[i][j]+matrix.array[i][j];
 return res;
 }
MAT MAT::operator - (MAT matrix)
 {
 MAT res(matrix.m,matrix.n);
 int i,j;
 for (i=0;i<matrix.m;i++)
  for (j=0;j<matrix.n;j++)
   res.array[i][j]=array[i][j]-matrix.array[i][j];
 return res;
 }
MAT MAT::operator * (MAT matrix)
 {
 MAT res(m,matrix.n);
 int i,j,k;
 for (i=0;i<m;i++)
  for (j=0;j<n;j++)
   for (k=0;k<matrix.m;k++)
   res.array[i][k]=res.array[i][k]+array[i][j]*matrix.array[j][k];
 return res;
 }
MAT MAT::operator / (MAT matrix)
 {
 MAT res(matrix.m,matrix.n);
 int i,j;
 for (i=0;i<matrix.m;i++)
  for (j=0;j<matrix.n;j++)
   res.array[i][j]=array[i][j]/matrix.array[i][j];
 return res;
 }

void main()
{
clrscr();
MAT a,b,c;
int ch;
cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\nChoice ? ";
cin >> ch;
cout << "Matrix 1 :\n";a.SetDimension();a.Get();
cout << "Matrix 2 :\n";
if (ch==1 || ch==2 || ch==4)
 b.SetDimension(a);
else
 {
 do
  {
  b.SetDimension();
  } while(a.cols()!=b.rows());
 }

b.Get();
switch (ch)
 {
 case 1:c=a+b;break;
 case 2:c=a-b;break;
 case 3:c=a*b;break;
 case 4:c=a/b;break;
 }
cout << "Resultant Matrix:\n";
c.Show();
getch();
}