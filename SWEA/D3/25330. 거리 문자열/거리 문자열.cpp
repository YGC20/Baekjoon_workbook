#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool listCheck(const string s) {
    vector<int> cnt(10,0);
    vector<int> idx(10,-1);
    for(int i=0;i<s.size();++i) {
        int num = s[i]-'0';
        if(cnt[num]>2) return false;
        if(idx[num]!=-1) {
            if((i-idx[num]-1)!=num) return false;
        }
        else {
            idx[num] = i;
        }
        cnt[num]++;
    }
    for(int c:cnt) {
        if(c==1) return false;
    }
    return true;
}
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		string s; cin>>s;
        if(listCheck(s)) cout<<"yes\n";
        else cout<<"no\n";
	}
	return 0;
}