// File Reversal
#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
char s[10000],c1,c2;
int i=0;
FILE*f1=fopen("test.txt","r");
FILE*f2=fopen("tmp.txt","w");
clrscr();
while (c1!=EOF)
 {
 c1=getc(f1);
 s[i++]=c1;
 }
printf("%s",s);
strrev(s);
fprintf(f2,"%s\n",s);
printf("%s",s);
fclose(f1);fclose(f2);
remove("test.txt");rename("tmp.txt","test.txt");
}