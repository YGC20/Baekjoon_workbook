#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        cout<<"#"<<test_case;
        for(int i=0;i<N;++i)
        {
            cout<<" 1/"<<N;
        }
        cout<<"\n";
	}
	return 0;
}