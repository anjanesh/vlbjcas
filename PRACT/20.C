/* File Listing of a Directoy */
#include <stdio.h>
#include <dir.h>
main(void)
{
 struct ffblk ffblk;
 int done;
 char typ[4]="",type[6]="*.";
 printf("Files of type (3 characters) ? ");
 scanf("%s",typ);
 strcat(type,typ);
 printf("Directory listing of *.");
 printf("%s",typ);printf("\n");
 done = findfirst(type,&ffblk,0);
 while (!done)
 {
  printf("  %s\t%ld bytes\n", ffblk.ff_name,ffblk.ff_fsize);
  done = findnext(&ffblk);
 }
}
