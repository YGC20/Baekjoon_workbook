#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv)
{
	int test_case = 1;
	for(; test_case <= 10; ++test_case)
	{
        int N = 0;
        cin>>N;
        string password = "";
        cin>>password;
        
        string pw = "";
        for(char p : password)
        {
            if(!pw.empty() && pw.back()==p)
            {
                pw.pop_back();
            }
            else
            {
            	pw+=p;
            }
        }
        cout<<"#"<<test_case<<" "<<pw<<"\n";
    }
	return 0;
}