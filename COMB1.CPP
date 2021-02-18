// All possible combinations of a string
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<timer.h>
unsigned long fact(unsigned long);
void swap(int[],int,int);
void display(int[],char*);
void Add(int[],int);
void main()
{
clrscr();
int j,k,n;
unsigned long i;
char strComb[20];
//Timer tmr;
//tmr.start();
cout << "String ? "; cin >> strComb;
n=strlen(strComb);
int*key=new int[n+1];
key[0]=n; // key[0] contains the total no: of digits
for (i=1;i<=key[0];i++)
 key[i]=i;
display(key,strComb);
swap(key,key[0],key[0]-1);display(key,strComb);
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
  display(key,strComb);
  swap(key,key[0],key[0]-1);display(key,strComb);
 }
cout << "\nTotal no: of combinations = " << key[0] << "! = " << i-1;// << tmr.time();
//tmr.stop();
getch();
}

unsigned long fact(unsigned long f)
{ return f==0?1:f*fact(f-1); }

void swap(int k[],int a,int b)
{int t=k[a];k[a]=k[b];k[b]=t;}

void display(int k[],char*str)
{
for(int i=1;i<=k[0];i++)
 cout << str[k[i]-1];
cout << '\t';
}

void Add(int k[],int i)
{
k[i]++;
if (k[i]==k[0]+1)
 k[i]=1;
}