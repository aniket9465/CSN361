#include<bits/stdc++.h> 
#include <unistd.h>
#include <stdlib.h>
//#include <sys types.h="">
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
using namespace std;
int main() 
{ 
	for(int i=0;i<5;i++) // loop will run n times (n=5) 
	{ 
		if(fork() == 0) 
		{ 
			if(i%2==0)
			sleep(1.5);
			printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid()); 
			exit(0); 
		} 
	} 
//         sleep(1);
	wait(NULL); 
	
} 
