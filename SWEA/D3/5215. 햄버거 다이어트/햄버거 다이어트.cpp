#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, L;
        cin>>N>>L;
        vector<pair<int,int>> materials(N);
        for(int i=0;i<N;++i)
        {
            cin>>materials[i].first>>materials[i].second;
        }
        vector<int> dp(L+1,0);
        for(int i=0;i<N;++i)
        {
            int score=materials[i].first;
            int cal=materials[i].second;
            for(int j=L;j>=cal;--j)
            {
                dp[j]=max(dp[j],dp[j-cal]+score);
            }
        }
        cout<<"#"<<test_case<<" "<<dp[L]<<"\n";
	}
	return 0;
}