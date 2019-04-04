#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int d,h,i,j, count=0;
	pid_t a[d];
	printf("degree\t");
	scanf("%d", &d);
	printf("height\t");
	scanf("%d", &h);
	
	printf("root %d\n", getpid());
	for(i=0; i<h; i++)
	{
		for(j=0; j<d; j++)
		{
			a[i] = fork();
			if(a[i] == 0)
				break;
			count++;	
		}
		if(count >= d)
			break;
		printf("child %d", getpid());
		printf("parent %d\n", getppid());
	}
	for(i=0; i<d; i++)
	{
		waitpid(a[i], NULL, 0);
	}
return 0;
}

