#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str; cin>>str;
        string tmp="";
        for(char s:str)
            if(s!='a' && s!='e' && s!='i' && s!='o' && s!='u')
                tmp+=s;
        cout<<"#"<<test_case<<" "<<tmp<<"\n";
	}
	return 0;
}