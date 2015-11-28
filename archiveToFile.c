#include "externs.h"
void archiveToFile()
{
  int fileCount = 0;
  for(fileCount = 0; fileCount < numOfFiles; fileCount++)
  {
    int numOfCharInName,numOfBytes;
    char fileName[100];
    fread(&numOfCharInName,sizeof(int),1,arc);//length of name
    printf("Num of Char in Filename:%d\n",numOfCharInName);
    fread(fileName,sizeof(char),numOfCharInName,arc);
    fileName[numOfCharInName] = '\0';
    printf("FileName:%s\n",fileName);
    fread(&numOfBytes,sizeof(int),1,arc);
    printf("Num of bytes:%d\n",numOfBytes);
    if((curFile = fopen(fileName,"w") ) == NULL)
    {printf("error"); exit(1);}
    int curByte;
    char curB;
    for(curByte = 0; curByte < numOfBytes; curByte++)
    {
      fread(&curB,sizeof(char),1,arc);
      printf("%c",curB);
      fprintf(curFile,"%c",curB);
    }
    fclose(curFile);
    
  }
}