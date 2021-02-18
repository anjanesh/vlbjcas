/* Stack Operations using pointers */
#include<stdio.h>
struct stack
{
int n;
struct stack *next;
}
*p,*q,*temp,*head=NULL;
main()
{
 int choice;
 clrscr();
 while(1)
 {
 clrscr();
 printf("\n 1.Push");
 printf("\n 2.Pop");
 printf("\n 3.Clear");
 printf("\n 4.Display");
 printf("\n 5.Quit");
 printf("\n Enter the choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
	push();
	getch();
	break;
 case 2:
	pop();
	getch();
	break;
 case 3:
       clear();
       getch();
       break;
 case 4:
       display();
       getch();
       break;
 default:
       exit(0);
       getch();
       break;
 }}}
 push()
 {
 temp=malloc(sizeof(struct stack));
 printf("\n Enter nunmber : ");
 scanf("%d",&temp->n);
 if(head==NULL)
 {
  head=temp;
  temp->next=NULL;
  }
  else
  {
   temp->next=head;
   head=temp;
   }
   printf("%d is pushed into the stack",temp->n);
   return(0);
   }
   pop()
   {
   p=head;
   if(head==NULL)
   printf("stack is empty");
   else
     {
    head=head->next;
    printf("%d is poped out from the stack",p->n);
    free(p);
    }
    return(0);
    }
    clear()
    {
    if(head==NULL)
    printf("stack is empty");
    else
    {
    p=head;
    while(p!=NULL)
    {
    head=head->next;
    if(head==NULL)
    printf("stack clear");
    free(p);
    p=p->next;
    }}return(0);
    }
    display()
    {
    if(head==NULL)
    printf("stack is empty");
    else
    {
    p=head;
    printf("element present in the stack");
    while(p!=NULL)
    {
    printf("\n %d ",p->n);
    p=p->next;
    }}
    return(0);
    }