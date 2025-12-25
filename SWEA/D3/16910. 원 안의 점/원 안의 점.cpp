#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        int N; cin>>N;
        long long cnt=0;
        for(int i=-N;i<=N;++i) {
            long long tmp=(long long)sqrt(N*N-i*i);
            cnt += (2*tmp+1);
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}