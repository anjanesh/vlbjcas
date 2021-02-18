#include <string.h>
char *fnchars(char* ,int);//returns a pointer pointing to the first n charecters of a string
char *lnchars(char* ,int);//returns a pointer pointing to the last n charecters of a string
char *mid(char *s,int start,int n);
char *Insert(char ,int ,char*);
char *Delete(int ,char*);
int *noofchar(char* ,char);//no of a particular charecter & their positions in the string
char* Ltrim(char*);//Removes leading white spaces
char* Rtrim(char*);//Removes trailing white spaces

char *fnchars(char *s,int n)
{
if (n>strlen(s)) return s;
char *st;
st = new char[n];
for (int i=0;i<n;i++)
 st[i]=s[i];
st[i]='\0';
return st;
}
char *lnchars(char *s,int n)
{
if (n>strlen(s)) return s;
char *st = new char[strlen(s)+1];strcpy(st,s);
for (int i=strlen(s)-1,j=n-1;j>=0;i--,j--)
 st[j]=s[i];
st[n]='\0';
return st;
}
char *mid(char *s,int start,int n)
{
char *st;
st=new char[start+1];
for (int i=start-1;i<start-1+n;i++)
 st[i-start+1]=s[i];
st[i-start+1]='\0';
return st;
}
char* Insert(char character,int position,char *string)
{
for(int i=strlen(string)+1;i>=position;i--)
 string[i]=string[i-1];
string[position-1]=character;
return string;
}
char* Delete(int position,char *string)
{
for (int i=position-1;i<=strlen(string)+1;i++)
 string[i]=string[i+1];
return string;
}

int *noofchar(char*s ,char c)
{
int n=0;
for (int i=0;i<strlen(s);i++)
 if (s[i]==c) n++;
int *no=new int[n+1];
no[0]=n;n=1;
for (i=0;i<strlen(s);i++)
 if (s[i]==c) no[n++]=i+1;
return no;
}

char* Ltrim(char *s)
{
for (int i=0;i<strlen(s);i++)
 if (s[i]!=' ') break;
s=lnchars(s,strlen(s)-i);
return s;
}

char* Rtrim(char *s)
{
for (int i=strlen(s)-1;i>=0;i--)
 if (s[i]!=' ') break;
s=fnchars(s,i+1);
return s;
}