/* Source Listings of programs */
#include <stdio.h>
#include <dir.h>
main(void)
{
 struct ffblk ffblk;
 int done,n,c=0,i;
 char*filenames[13],ch;
 FILE*sfile;
 printf("No: of files ?");scanf("%d",&n);
 *filenames=(char*)malloc(n*13*sizeof(char));
 for (i=0;i<n;i++)
  {
  printf("File %d : ",i+1);
  scanf("%s",filenames[i]);
  }
 done = findfirst("*.c",&ffblk,0);
 if (!done)
  strcpy(filenames[c++],ffblk.ff_name);
 while (!done)
 {
  strcpy(filenames[c++],ffblk.ff_name);
  done = findnext(&ffblk);
 }
 for (i=0;i<n;i++)
  {
  sfile=fopen(filenames[i],"r");
  do
   {
    ch = fgetc(sfile);
    putch(ch);
    if (ch=='\n') putch('\r');
   } while (ch != EOF);
  }
}
