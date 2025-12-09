#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int L,R; cin>>L>>R;
        if(2*L<=R)
            cout<<"no\n";
        else
            cout<<"yes\n";
	}
	return 0;
}