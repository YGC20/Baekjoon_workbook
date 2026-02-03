#include<iostream>
#include<string>
using namespace std;
int solution(int testCase) {
    string ans, str;
    cin>>ans>>str;
    
    string stk = "";
    int cnt = 0;
    int patternLen = ans.length();
    
    for(char s : str) {
        stk += s;
        if(stk.size() >= patternLen && stk.back() == ans.back()) {
            if(stk.substr(stk.size() - patternLen) == ans) {
                for(int i=0; i<patternLen; ++i) {
                	stk.pop_back();
                }
                cnt++;
            }
        }
    }
    cout<<"#"<<testCase<<" "<<cnt<<"\n";
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1; i<=10; ++i) {
        int testCase;
        cin>>testCase;
        solution(testCase);
    }
	return 0;
}