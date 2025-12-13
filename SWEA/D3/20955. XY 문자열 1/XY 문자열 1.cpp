#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		string S,E; cin>>S>>E;
        int cnt = E.length()-S.length();
        bool flag = false;
        for(int i=cnt;i>0;--i) {
            if(E.back()=='X') {
                E.pop_back();
            }
            else {
                E.pop_back();
                reverse(E.begin(),E.end());
            }
             if(S==E) {
                flag=true;
                break;
            }
        }
        if(flag) cout<<"#"<<test_case<<" Yes\n";
        else cout<<"#"<<test_case<<" No\n";
	}
	return 0;
}