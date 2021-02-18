/* To print the ascii values of a WordStar text file */
#include<stdio.h>
#include<conio.h>
main()
{
char c='\0';
char s[10];
int i;
FILE*f1=fopen("wordstar.txt","r");
FILE*f2=fopen("ascii.txt","w");
clrscr();
do
 {
 c=fgetc(f1);
 printf("%d\t",c);
 fprintf(f2,"%d\n",c);
 } while ((c=fgetc(f1))!=EOF);
fclose(f1);fclose(f2);
}