#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int N,K; cin>>N>>K;
        vector<int> pak(N,0);
        for(int i=0;i<N;++i)
            cin>>pak[i];
        sort(pak.rbegin(),pak.rend());
        int min = 1000000000;
        for(int i=0;i<N;++i) {
            int start = i, end = i+K-1;
            if(end<N) {
                int tmp = pak[start]-pak[end];
            	if(tmp<min)
                	min = tmp;
            }
        }
        cout<<"#"<<test_case<<" "<<min<<"\n";
	}
	return 0;
}