#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string word="";
        cin>>word;
        int subSize=word.size()/2;
        int secondStart=(word.size()%2==0)?subSize:subSize+1;
        string tmp1=word.substr(0,subSize);
        string tmp2=word.substr(secondStart,subSize);
        reverse(tmp2.begin(),tmp2.end());
        cout<<"#"<<test_case<<" ";
        if(tmp1==tmp2)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
	}
	return 0;
}