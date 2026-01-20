#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str = "";
        cin>>str;
        reverse(str.begin(),str.end());
        for(int i=0;i<str.size();++i)
        {
            if(str[i]=='p')
            {
                str[i]='q';
            }
            else if(str[i]=='q')
            {
                str[i]='p';
            }
            else if(str[i]=='b')
            {
                str[i]='d';
            }
            else if(str[i]=='d')
            {
                str[i]='b';
            }
        }
        cout<<"#"<<test_case<<" "<<str<<"\n";
	}
	return 0;
}