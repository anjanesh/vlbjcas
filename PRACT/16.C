/* Menu driven program of Employe DB using Files */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
struct Datatype_Employee
 {
 char ID[10],name[50],designation[20];
 int salary;
 };
typedef struct Datatype_Employee Employee;
void Add(FILE*);
Employee Delete(FILE*);
void Info(FILE*);
void TotalNoOfEmployees(FILE*);
void Show(FILE*);

main()
{
FILE*empfile=fopen("employee.dat","r+");
int ch;
fclose(empfile);
do
 {
 clrscr();
 printf("1 > Add    +\n");
 printf("2 > Delete X\n");
 printf("3 > Search ?\n");
 printf("4 > Total  N\n");
 printf("5 > View   ð\n");
 printf("6 > Exit   ->\n");
 printf("Choice ?  ");scanf("%d",&ch);
 clrscr();
 switch(ch)
  {
  case 1:Add(empfile);break;
  case 2:Delete(empfile);break;
  case 3:Info(empfile);break;
  case 4:TotalNoOfEmployees(empfile);break;
  case 5:Show(empfile);break;
  case 6:break;
  default:printf("Wrong choice !!!");
  }
 } while(ch!=6);
}

void Add(FILE*fp)
{
Employee e;
fp=fopen("employee.dat","a");
printf("ID : ");scanf("%s",e.ID);
printf("Name : ");scanf("%s",e.name);
printf("Designation : ");scanf("%s",e.designation);
printf("Salary : ");scanf("%d",&e.salary);
fprintf(fp,"%s\n%s\n%s\n%d\n",e.ID,e.name,e.designation,e.salary);
printf("\n1 Employee record added....Hit any key to continue");
fclose(fp);
getch();
}

void TotalNoOfEmployees(FILE*fp)
{
int count=0;
Employee e;
fp=fopen("employee.dat","r");
while (!feof(fp))
 {
 fscanf(fp,"%s%s%s%d",e.ID,e.name,e.designation,&e.salary);
 count++;
 }
printf("No: of employees = %d",count);
printf("\nHit any key to continue");
fclose(fp);
getch();
}

Employee Delete(FILE*fp)
{
Employee e;
int flag=0;
char *search=(char*)malloc(50*sizeof(char));
FILE*f1=fopen("temp.dat","w");
fp=fopen("employee.dat","r");
printf("Enter Employee ID : ");scanf("%s",search);
while (!feof(fp))
 {
 fscanf(fp,"%s%s%s%d",e.ID,e.name,e.designation,&e.salary);
 if (strcmp(e.ID,search)!=0)
  {
  fprintf(f1,"\n%s\n%s\n%s\n%d",e.ID,e.name,e.designation,e.salary);
  flag=1;
  }
 }
if (!flag)
 printf("\nEmployee record not found ! .............");
else
 printf("\n1 Employee record deleted ! .............");
printf("Hit any key to continue");
fclose(fp);fclose(f1);
system("del employee.dat");
system("ren temp.dat employee.dat");
getch();
}

void Info(FILE*fp)
{
Employee e;
char *search=(char*)malloc(50*sizeof(char));
int flag=0;
fp=fopen("employee.dat","r");
printf("Enter Employee's name : ");
scanf("%s",search);
while (!feof(fp))
 {
 fscanf(fp,"%s%s%s%d",e.ID,e.name,e.designation,&e.salary);
 if (strcmp(e.name,search)!=0)
  {
  printf("%s\t%s\t%s\t%d\n",e.ID,e.name,e.designation,e.salary);
  flag=1;
  }
 }
if (!flag)
 printf("\nEmployee record not found ! .............");
printf("Hit any key to continue");
fclose(fp);
getch();
}

void Show(FILE*fp)
{
Employee e;
fp=fopen("employee.dat","r");
while (!feof(fp))
 {
 fscanf(fp,"%s%s%s%d",e.ID,e.name,e.designation,&e.salary);
 printf("%s\t%s\t%s\t%d\n",e.ID,e.name,e.designation,e.salary);
 }
printf("\nHit any key to continue");
fclose(fp);
getch();
}