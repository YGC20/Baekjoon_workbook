#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		string S; cin>>S;
        int cnt; cin>>cnt;
        for(int i=0;i<cnt;++i) {
            if(S=="o..")
                S=".o.";
            else if(S==".o.")
                S="o..";
            else if(S=="..o")
                S=".o.";
        }
        for(int i=0;i<3;++i) {
            if(S[i]=='o')
                cout<<"#"<<test_case<<" "<<i<<"\n";
        }
	}
	return 0;
}