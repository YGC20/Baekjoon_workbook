#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int TC;	cin>>TC;
	for(test_case = 1; test_case <= TC; ++test_case)	{
		long long N; cin>>N;
        long long min=N;
        for(int i=1;i<=sqrt(N);++i) {
            if(N%i==0) {
                long long mv=(i-1)+(N/i-1);
                if(mv<min) min=mv;
            }
        }
        cout<<"#"<<test_case<<" "<<min<<"\n";
	}
	return 0;
}