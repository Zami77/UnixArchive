#include "externs.h"

void pluckArchive()
{
  int fileFound = 0;
  int nameIsGood = 1;
  int fileCount = 0;
  for(fileCount = 0; fileCount < numOfFiles; fileCount++)
  {
    int numOfCharInName,numOfBytes;
    char fileName[100];
    fread(&numOfCharInName,sizeof(int),1,arc);//length of name
    //printf("Num of Char in Filename:%d\n",numOfCharInName);
    fread(fileName,sizeof(char),numOfCharInName,arc);
    fileName[numOfCharInName] = '\0';
    //printf("FileName:%s\n",fileName);
    fread(&numOfBytes,sizeof(int),1,arc);
    //printf("Num of bytes:%d\n",numOfBytes);
    int curByte;
    char curB;
    for(curByte = 0; curByte < numOfBytes; curByte++)
    {
      fread(&curB,sizeof(char),1,arc);
    }
    nameIsGood = 1;
    if((strlen(prefix)) <= (strlen(fileName)))
    {
      int i;
      for(i = 0; i < strlen(prefix); i++)//checks indexes of prefix and filename against eachother
      {
        //printf("prefix[%d]:%c vs. fileName[%d]:%c\n",i,prefix[i],i,fileName[i]);
        if(prefix[i] != fileName[i])
        {
          //printf("Are not equal");
          nameIsGood = 0;
        }
      
      }
      if(nameIsGood)
      {
        fileFound = 1;
        printf("FileName:%s\n",fileName);
        printf("Size of File(bytes):%d",numOfBytes);
      }
    }
  }
  if(!fileFound)
    printf("No Files were found...");
}
