#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int TC;	cin>>TC;
	for(test_case = 1; test_case <= TC; ++test_case)	{
        int N; cin>>N;
        string S; cin>>S;
        string tmp1=S.substr(0,N/2);
        string tmp2=S.substr(N/2);
        if(tmp1==tmp2) cout<<"#"<<test_case<<" Yes\n";
        else cout<<"#"<<test_case<<" No\n";
	}
	return 0;
}