#include <stdio.h>
void main()
{
  int ch=0;
  FILE *fp=fopen("test.bin","rb"); //actually test.bin is in the same folder that's why whole path is not important
  if (fp==NULL)
    printf("File is not open");  // fopen() on faliure returns NULL i.e. no such file
  while (ch!=EOF)
       {
  ch=fgetc(fp);  // this is the character to character reading method 
  printf("%c",ch); // where fgetc() returns ASCII value of each char which has been stored int ch 
    }               // EOF is basically a variable that indicates end of the file and it's value is '-1'
  fclose(fp);
}
