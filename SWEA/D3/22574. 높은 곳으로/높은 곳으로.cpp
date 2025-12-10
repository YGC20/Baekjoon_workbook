#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		long long N,P; cin>>N>>P;
        long long floor = 0;
        for(int i=1;i<=N;++i) {
            floor+=i;
            if(floor==P)
                floor--;
        }
        cout<<floor<<"\n";
	}
	return 0;
}