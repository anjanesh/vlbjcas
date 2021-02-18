/* Stack Operations using functions */
struct Datatype_stack
 {
 int st[100];
 int top;
 };
typedef struct Datatype_stack stack;
void Push(stack*,int);
int Pop(stack*);
void Show(stack*);
main()
{
stack *stk;
stk->top=0;
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
{ s->st[s->top++]=a; }

int Pop(stack*s)
{ return !s->top?-1:s->st[s->top---1]; }

void Show(stack*s)
{
int i;
for(i=0;i<s->top;i++)
 printf("%d\t",s->st[i]);
printf("\n");
}