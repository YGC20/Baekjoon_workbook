#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str[3];
        cin>>str[0]>>str[1]>>str[2];
        string ans = "";
        for(int i=0; i<3; ++i)
        {
            ans+=str[i][0]-'a'+'A';
        }
        cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}