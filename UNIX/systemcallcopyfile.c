#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
char buffer[3000];
//int v=1;
void filefun(int old,int new){

	int count;
	while((count=read(old,buffer,sizeof(buffer)))>0){
		write(new,buffer,count);
	}
}

int main(int argc,char*argv[])

{

	int fsource,fdestination;
	if(argc!=3){
		printf("Enter source file name and also destination file name also...");
		exit(1);		
	}
	fsource=open(argv[1],O_RDONLY);
	if(fsource==-1){
		printf("Firstly write some data into source file");
	}
	fdestination=creat(argv[2],O_RDWR);
	if(fdestination==-1){
		printf("File not created");
	}
	filefun(fsource,fdestination);
	exit(1);
}
