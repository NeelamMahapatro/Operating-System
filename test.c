#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fnctl.h>
#include<stdlib.h>
#define file "test.txt"

int main()
{
	pid_t p,q;
	int p1, c1, gc1, gc2, fd;
	int rcvr, len;
	char s[200];
	p1 = getpid();	
	mkfifo(file, 0666);
	p= fork();

	if(p == 0)
	{
		c1 = getpid();
		q = fork();
		if(q != 0)
			gc2 = getpid();
		gc1 = getpid();
	}
	
		if(getpid() == p1)
		{	
			printf("Give message\n");
			scanf("%d", &rcvr);
			fd = open(file, O_WRONLY);
			write(fd, &rcvr, 4);
			scanf("%d", &len);
			write(fd, &len, 4);
			scanf("%s", &s);
			write(fd, s, strlen(s));
			close(fd);			
		}
	
	
return 0;
}
