#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h> 

using namespace std;
int main()
{
	if(fork()==0)
	{
		sleep(2);
		cout<<"\nThis is an orphan process\n";
		if(fork()==0)
		{
			cout<<"Child finished\n";
			return 0;
		}
		sleep(2);
		cout<<"Child process is a zombie process\n";
		return 0;
	}
	cout<<"parent finished\n";
}