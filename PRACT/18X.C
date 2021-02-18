/* Stack Operations using pointers */
#include<stdio.h>
struct Datatype_stack
 {
 int st;
 struct Datatype_stack*next;
 };
typedef struct Datatype_stack stack;
void Push(stack*,int);
int Pop(stack*);
void Show(stack*);
main()
{
stack*stk=(stack*)malloc(sizeof(stack));
stk->next=NULL;
Push(stk,10);
Push(stk,23);
Push(stk,68);
Push(stk,50);
Show(stk);
printf("Popped out : %d\n",Pop(stk));
Show(stk);
printf("Popped out : %d\n",Pop(stk));
Show(stk);
}

void Push(stack*s,int a)
{
stack*p=s;
stack*t=(stack*)malloc(sizeof(stack));
while (p->next!=NULL) { p=p->next; }
p->st=a;
p->next=t;
t->next=NULL;
}

int Pop(stack*s)
{
stack*p=s;
stack*back=(stack*)malloc(sizeof(stack));
while (p->next!=NULL)
{
back->next=p->next;
p=p->next;
}
if (s!=NULL)
 {
 s->st;

 }


}

void Show(stack*s)
{
int i;
stack*p=s;
while (p->next!=NULL)
 {
 printf("%d\t",p->st);
 p=p->next;
 }
}