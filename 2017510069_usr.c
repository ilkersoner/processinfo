#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc,char* argv[])
{
	
	if(argc==1) {
		printf("Right Usage:\n-all prints some information (process id and itsargument/s) about all processes\n-p takes process id and prints the details of it\n-k takes process id\n");
	}
	else if(argc==2) {
		if(strcmp(argv[1],"-all")==0) {
			long int sysId = syscall(335,0,0);
			printf("-all falan");
		}
		else {
			printf("Right Usage:\n-all prints some information (process id and itsargument/s) about all processes\n-p takes process id and prints the details of it\n-k takes process id\n");
		}
	}
	else if(argc==3) {
		if(strcmp(argv[1],"-p")==0) {
			char* p;
			int num;
			long conv=strtol(argv[2],&p,10);
			num=conv;
			long int sysId = syscall(335,num,0);
			printf("-p falan");
		}
		else if(strcmp(argv[1],"-k")==0) {
			char* p;
			int num;
			long conv=strtol(argv[2],&p,10);
			num=conv;
			int a=kill(num,SIGKILL);
			long int sysId = syscall(335,num,1);
			if(a==0){
				printf("Process with %d id is succesfully killed.\n",num);
			}
			else
				printf("Process cannot be killed\n");
		}
		else {
			printf("Right Usage:\n-all prints some information (process id and itsargument/s) about all processes\n-p takes process id and prints the details of it\n-k takes process id\n");
		}
	}
	else {
		printf("Right Usage:\n-all prints some information (process id and itsargument/s) about all processes\n-p takes process id and prints the details of it\n-k takes process id\n");
	}
return 0;
}
