#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool checkStr(const string s) {
    string tmp = s;
    reverse(tmp.begin(),tmp.end());
    return s==tmp;
}
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
    for(test_case = 1; test_case <= T; ++test_case) {
		string S; cin>>S;
        int n = S.length();
        bool flag = true;
        
        if(!checkStr(S)) flag = false;
        string s1 = S.substr(0,(n-1)/2);
        if(!checkStr(s1)) flag = false;
        string s2 = S.substr((n+1)/2);
        if(!checkStr(s2)) flag = false;
        
        if(flag)
            cout<<"#"<<test_case<<" YES\n";
        else
            cout<<"#"<<test_case<<" NO\n";
	}
	return 0;
}