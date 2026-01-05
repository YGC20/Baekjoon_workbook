#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string memo; cin>>memo;
        int cnt=0;
        char preMemo='0';
        for(char m:memo)
        {
            if(preMemo!=m)
            {
                cnt++;
                preMemo=m;
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
    }
	return 0;
}