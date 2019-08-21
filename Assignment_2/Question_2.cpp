#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h> 

using namespace std;
int main()
{
	if(fork()==0)
	{
		sleep(2);
		cout<<"\nParent is an orphan process as grandparent is finished "<<getpid()<<"\n";
		if(fork()==0)
		{
			cout<<"Child finished "<<getpid()<<"\n";
			return 0;
		}
		sleep(1);
		cout<<"Child process is a zombie process as parent is sleeping\n";
		sleep(2);
		return 0;
	}
	cout<<"grandparent finished "<<getpid()<<"\n";
}