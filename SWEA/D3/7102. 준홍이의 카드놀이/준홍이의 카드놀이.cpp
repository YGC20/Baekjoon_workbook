#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M; cin>>N>>M;
        int nums[N+M+1]={0};
        for(int i=1;i<=N;++i)
        {
            for(int j=1;j<=M;++j)
            {
                nums[i+j]+=2;
            }
        }
        int max=0;
        for(int i=0;i<=N+M;++i)
            if(nums[i]>max)
                max=nums[i];
        cout<<"#"<<test_case;
        for(int i=0;i<=N+M;++i)
        {
            if(nums[i]==max)
                cout<<" "<<i;
        } cout<<"\n";
    }
	return 0;
}