#include "externs.h"

int main(int argc,char* argv[])
{
	if(strcmp(argv[1],"-c") == 0)
	{
		numOfFiles = argc - 3;//getting num of files from command line arguments
    printf("numOfFiles:%d\n",numOfFiles);
		arc = fopen(argv[2],"w+");
		fwrite(&numOfFiles,sizeof(int),1,arc);//write number of files to Binary
		for(j = 3; j < argc; j++)
		{
			strcpy(curName,argv[j]);
      printf("Curname:%s\n",curName);
			curFile = fopen(curName,"r");
			
			writeToArchive();
      fclose(curFile);
			
			
		}

		//create archive
	}
	else if(strcmp(argv[1],"-x") == 0)
	{
    arc = fopen(argv[2],"rb");
    fread(&numOfFiles,sizeof(int),1,arc);
    printf("NumOfFiles:%d\n",numOfFiles);
    archiveToFile();
		//extract archive
	}
	else if(strcmp(argv[1],"-p") == 0)
	{
    arc = fopen(argv[3],"rb");
    fread(&numOfFiles,sizeof(int),1,arc);
    printf("NumOfFiles:%d\n",numOfFiles);
    strcpy(prefix,argv[2]);
    printf("Prefix:%s\n",prefix);
    pluckArchive();  
		//pluck Archive
	}
	else
	{
		printf("Improper comamand line args");
		exit(1);
	}
}