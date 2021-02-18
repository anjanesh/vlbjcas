/* To find the GCD (Greatest Common Divisor) of 2 numbers */
int gcd(int,int);
main()
{
int divisor,dividend;
printf("Enter number 1 : ");scanf("%d",&dividend);
printf("Enter number 2 : ");scanf("%d",&divisor);
printf("Greatest Common Divisor (GCD) of %d & %d = %d",dividend,divisor,gcd(dividend,divisor));
}
int gcd(int dv,int dr)
{
return (dv%dr!=0)?gcd(dr,dv%dr):dr;
}
