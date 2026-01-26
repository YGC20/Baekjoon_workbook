#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case = 1;
	int T;
	cin>>T;
	for(; test_case <= T; ++test_case)
	{
		int N = 0;
        cin>>N;
        string winner = "";
        if((N-1)%2==0)
        {
            winner = "Bob";
        }
        else
        {
            winner = "Alice";
        }
        cout<<"#"<<test_case<<" "<<winner<<"\n";
	}
	return 0;
}