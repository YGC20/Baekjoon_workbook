#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        string A,B; cin>>A>>B;
        string answer = "";
        if(A==B) answer=A;
        else answer="1";
        cout<<"#"<<test_case<<" "<<answer<<"\n";
	}
	return 0;
}