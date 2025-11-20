#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        string tc = to_string(test_case);
        string tmp = "";
        int tcCnt = 0;
        for(int i=0;i<tc.size();++i){
            if(tc[i]=='3' || tc[i]=='6' || tc[i]=='9') tcCnt++;
        }
        for(int i=0;i<tcCnt;++i){
            tmp+='-';
        }
        if(!tmp.empty())
            cout<<tmp<<" ";
        else
            cout<<tc<<" ";
	}
	return 0;
}