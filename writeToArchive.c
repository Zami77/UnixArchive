#include "externs.h"
void writeToArchive()
{
	strLen = strlen(curName);
	fwrite(&strLen,sizeof(int),1,arc);//write length of name
	fwrite(&curName,strLen,1,arc);//write actual name
	stat(curName,&curStat);
	lenOfFile = curStat.st_size;
  printf("length of File:%d\n",lenOfFile);
  fwrite(&lenOfFile,sizeof(int),1,arc);//write length of file to archive
  rewind(curFile);
  int c;
  char cSwitch;
	for(i = 0; i < lenOfFile; i++)
  {
    c = fgetc(curFile);
    cSwitch = (char)c;
    printf("%c",cSwitch);
    fwrite(&cSwitch,sizeof(char),1,arc);
  }
	
}
