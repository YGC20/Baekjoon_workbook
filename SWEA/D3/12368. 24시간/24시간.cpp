#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int A, B;
        cin>>A>>B;
        cout<<"#"<<test_case<<" "<<(A+B)%24<<"\n";
	}
	return 0;
}