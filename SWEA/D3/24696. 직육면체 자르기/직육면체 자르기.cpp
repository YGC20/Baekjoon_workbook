#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int a,b,c; cin>>a>>b>>c;
        int cnt = (a-1)+(a*(b-1))+(a*b*(c-1));
        if(cnt%2==0||cnt==0) cout<<"2\n";
        else cout<<"1\n";
	}
	return 0;
}