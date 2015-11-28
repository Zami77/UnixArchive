#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#define MODE 0777

void writeToArchive();
void archiveToFile();
void pluckArchive();
int archive,j,i,strLen,lenOfFile,numOfFiles;
char curName[100];
char prefix[100];
FILE* arc;
FILE* curFile;
struct stat curStat;