// All possible combinations upto n digits
#include<fstream.h>
#include<conio.h>
unsigned long fact(unsigned long);
void swap(int[],int,int);
void display(int[]);
void Add(int[],int);
ofstream fout("combtion.txt");
void main()
{
clrscr();
int j,k,n;
unsigned long i;
cout << "How many digits ? "; cin >> n;
int*key=new int[n+1];
key[0]=n; // key[0] contains the total no: of digits
for (i=1;i<=key[0];i++)
 key[i]=i;
display(key);
swap(key,key[0],key[0]-1);display(key);
for (i=3;i<=fact(key[0]);i+=2)
 {
 for (j=key[0]-1;j>=0;j--)
  {
  if ((i-1)%fact(j)==0)
   {
   Add(key,key[0]-j);
   for (k=1;k<=key[0]-j-1;k++)
    if (key[k]==key[key[0]-j])
      {Add(key,key[0]-j);k=0;}
   }
  }
  display(key);swap(key,key[0],key[0]-1);display(key);
 }
cout << "\nTotal no: of combinations = " << key[0] << "! = " << i-1;
fout.close();
}

unsigned long fact(unsigned long f)
{ return f==0?1:f*fact(f-1); }

void swap(int k[],int a,int b)
{int t=k[a];k[a]=k[b];k[b]=t;}

void display(int k[])
{
for(int i=1;i<=k[0];i++)
 cout << k[i];
cout << '\t';
}

void Add(int k[],int i)
{
k[i]++;
if (k[i]==k[0]+1)
 k[i]=1;
}