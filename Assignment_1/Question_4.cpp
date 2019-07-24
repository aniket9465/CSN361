#include<bits/stdc++.h>
using namespace std;

void host_from_ip(char c[100]){
	char cm[50]={'h','o','s','t',' '};
	char qu[50]={};
	strcpy(qu,strcat(cm,c));
	cout<<qu<<endl;
	system(qu);
}
int main(void)
{
    char c[100];
    cout<<"Enter IP Address : ";
    cin>>c;
    cout<<c<<endl;
    host_from_ip(c);
    return 0;
}