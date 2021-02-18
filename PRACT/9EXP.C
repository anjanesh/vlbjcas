/* To find the GCD (Greatest Common Divisor) of 2 numbers */
int gcd(int,int);
int gcdrec(int,int);
main()
{
int divisor,dividend;
printf("Enter number 1 : ");
scanf("%d",&dividend);
printf("Enter number 2 : ");
scanf("%d",&divisor);
printf("Greatest Common Divisor (GCD) of %d & %d using normal function = %d\n",dividend,divisor,gcd(dividend,divisor));
printf("Greatest Common Divisor (GCD) of %d & %d using recurrsive function = %d",dividend,divisor,gcdrec(dividend,divisor));
}

int gcd(int dv,int dr)
{
int rem=1;
while(rem!=0)
 {
 rem=dv%dr;
  if (rem!=0)
   {
   dv=dr;
   dr=rem;
   }
 }
return dr;
}

int gcdrec(int dv,int dr)
{
int g;
int rem=dv%dr;
if (rem!=0)
 g=gcdrec(dr,rem);
else
 g=dr;
return g;
}