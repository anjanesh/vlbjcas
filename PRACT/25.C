/* Comparisions of 2 files */
#include<stdio.h>
#include<conio.h>
main()
{
char s[80]="",c1,c2;
int i=1;
FILE*f1=fopen("file1.txt","w");
FILE*f2=fopen("file2.txt","w");
clrscr();
while (strcmp(s,"xxx")!=0)
 { gets(s); fprintf(f1,"%s\n",s); }
fclose(f1);
s[0]='\0';
while (strcmp(s,"xxx")!=0)
 { gets(s); fprintf(f2,"%s\n",s); }
fclose(f2);
f1=fopen("file1.txt","r");
f2=fopen("file2.txt","r");
while (c1!=EOF || c2!=EOF)
 {
 c1=getc(f1);
 c2=getc(f2);
 printf("Position %d : ",i++);
 c1==c2?printf("Same\n"):printf("Different\n");
 }
fclose(f1);fclose(f2);
}