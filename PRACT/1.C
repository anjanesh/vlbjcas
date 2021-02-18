/* Finds the sum, product, average, largest, smallest */
main()
{
int a,b,c;
int sum,product,smallest,largest;
float average;
printf("Enter the 1st number: ");
scanf("%d",&a);
printf("Enter the 2nd number: ");
scanf("%d",&b);
printf("Enter the 3rd number: ");
scanf("%d",&c);
sum=a+b+c;
average=(float)sum/3;
product=a*b*c;
largest=a;
if (b > a) largest=b;
if (c > a || c > b) largest=c;
smallest=a;
if (b < a) smallest=b;
if (c < a || c < b) smallest=c;
printf("\nSum of the three numbers = %d\n",sum);
printf("Product of the three numbers = %d\n",product);
printf("Average of the three numbers = %f\n",average);
printf("Smallest of the three numbers = %d\n",smallest);
printf("Largest of the three numbers = %d\n",largest);
}