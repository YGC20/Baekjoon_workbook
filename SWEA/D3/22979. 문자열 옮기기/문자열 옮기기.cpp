#include<iostream>
#include<string>
#include<list>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		string S; cin>>S;
        long long move = 0;
        int t; cin>>t;
        for(int i=0;i<t;++i) {
            int tmp; cin>>tmp;
            move+=tmp;
        }
        long long len = (long long)S.length();
        long long start = move % len;
        if(start<0)
            start+=len;
        cout<<S.substr(start)<<S.substr(0,start)<<"\n";
	}
	return 0;
}