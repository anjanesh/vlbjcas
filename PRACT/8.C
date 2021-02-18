/* Convert an integer from 1 to 100 to words */
main()
{
int n,a,b;
char tens[][10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
char units[][10]={"","one","two","three","four","five","six","seven","eight","nine"};
char teens[][15]={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
printf("\nEnter a number from 1 to 100 : ");
scanf("%d",&n);
b=n%10;
a=n/10;
if (n>10 && n<20)
 printf("%s",teens[b-1]);
else
 printf("%s %s",tens[a],units[b]);
}