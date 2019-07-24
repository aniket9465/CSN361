#include<bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main()
{
	for(int i=0;i<2;++i)
	{
		if(fork()==0)
		{
			for(int j=0;j<2;++j)
			{
				if(fork()==0)
				{
					cout<<"grandchild "<<i*2+(j+1)<<" process id: "<<getpid()<<"\n";	
					exit(0);
				}
			}
			sleep(1);
			cout<<"child "<<(i+1)<<" process id: "<<getpid()<<"\n";
			exit(0);
		}
	}
	sleep(2);
	cout<<"Main process id: "<<getpid()<<"\n";
}
