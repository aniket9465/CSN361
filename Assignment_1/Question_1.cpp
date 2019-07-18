#include<bits/stdc++.h>
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
					
					exit(0);
				}
			}
			exit(0);
		}
	}
}
