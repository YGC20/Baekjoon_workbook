#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int TC;
	cin>>TC;
	for(test_case = 1; test_case <= TC; ++test_case)
	{
        int N;
        cin>>N;
        cout<<"#"<<test_case<<" "<<N*N<<"\n";
	}
	return 0;
}