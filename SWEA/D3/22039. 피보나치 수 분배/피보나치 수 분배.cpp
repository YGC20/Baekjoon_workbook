#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int N; cin>>N;
        if(N%3==0) {
            for(int i=0;i<N/3;++i)
                cout<<"BBA";
        }
        else if(N%3==1) {
            cout<<"impossible";
        }
        else if(N%3==2) {
            cout<<"BA";
            for(int i=0;i<(N-2)/3;++i)
                cout<<"BBA";
        }
        cout<<"\n";
	}
	return 0;
}