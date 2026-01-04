#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string command; cin>>command;
        int a=1, b=1;
        for(char c:command)
        {
            if(c=='L')
                b+=a;
            else if(c=='R')
                a+=b;
        }
        cout<<"#"<<test_case<<" "<<a<<" "<<b<<"\n";
	}
	return 0;
}