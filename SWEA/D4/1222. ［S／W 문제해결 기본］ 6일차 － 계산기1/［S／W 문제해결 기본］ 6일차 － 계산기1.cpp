#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case = 1;
	for(test_case; test_case <= 10; ++test_case)
	{
        int str_length = 0;
        cin>>str_length;
        string str = "";
        cin>>str;
        int result = 0;
        for(char s : str)
        {
            if(s!='+')
            {
                result += (s-'0');
            }
        }
        cout<<"#"<<test_case<<" "<<result<<"\n";
	}
	return 0;
}