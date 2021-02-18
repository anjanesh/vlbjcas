/* Menu driven program of Employe DB using Linked lists */
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct Datatype_Employee
 {
 char ID[10],name[50],designation[20];
 int salary;
 struct Datatype_Employee *next;
 };
typedef struct Datatype_Employee Employee;
void Add(Employee*);
Employee Delete(Employee*);
void Info(Employee*);
void TotalNoOfEmployees(Employee*);
void Show(Employee*);

main()
{
Employee *emp=(Employee*)malloc(sizeof(Employee));
int ch;
emp->next=NULL;
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
  case 1:Add(emp);break;
  case 2:Delete(emp);break;
  case 3:Info(emp);break;
  case 4:TotalNoOfEmployees(emp);break;
  case 5:Show(emp);break;
  case 6:break;
  default:printf("Wrong choice !!!");
  }
 } while(ch!=6);
}

void Add(Employee*pemp)
{
Employee*p=pemp;
Employee*e=(Employee*)malloc(sizeof(Employee));
p=pemp;
while (p->next!=NULL) { p=p->next; }
printf("ID : ");scanf("%s",p->ID);
printf("Name : ");scanf("%s",p->name);
printf("Designation : ");scanf("%s",p->designation);
printf("Salary : ");scanf("%d",&p->salary);
p->next=e;
e->next=NULL;
printf("\n1 Employee record added....Hit any key to continue");
getch();
}

void TotalNoOfEmployees(Employee*pemp)
{
int count=0;
Employee*p=pemp;
while (p->next!=NULL)
 { p=p->next; count++; }
printf("No: of employees = %d",count);
printf("\nHit any key to continue");
getch();
}

Employee Delete(Employee*pemp)
{
Employee*p=pemp,*back;
char *search=(char*)malloc(50*sizeof(char));
int flag=0;
printf("Enter Employee ID : ");
scanf("%s",search);
while (p->next!=NULL)
 {
 if (strcmp(p->ID,search)==0)
  {
  back->next=p->next;
  flag=1;
  }
 back=p;
 p=p->next;
 }
if (!flag)
 printf("\nEmployee record not found ! .............");
else
 printf("\n1 Employee record deleted ! .............");
printf("Hit any key to continue");
getch();
}

void Info(Employee*pemp)
{
Employee*p=pemp;
char *search=(char*)malloc(50*sizeof(char));
int flag=0;
printf("Enter Employee's name : ");
scanf("%s",search);
while (p->next!=NULL)
 {
 if (strcmp(p->name,search)==0)
  {
  printf("%s\t%s\t%s\t%d\n",p->ID,p->name,p->designation,p->salary);
  flag=1;
  }
 p=p->next;
 }
if (!flag)
 printf("\nEmployee record not found ! ");
printf("\nHit any key to continue");
getch();
}

void Show(Employee*pemp)
{
Employee*p=pemp;
while (p->next!=NULL)
 {
 printf("%s\t%s\t%s\t%d\n",p->ID,p->name,p->designation,p->salary);
 p=p->next;
 }
printf("\nHit any key to continue");
getch();
}