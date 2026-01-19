#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N=0, M=0;
        cin>>N>>M;
        int A[N]={0}, B[M]={0};
        for(int i=0;i<N;++i)
        {
            cin>>A[i];
        }
        for(int i=0;i<M;++i)
        {
            cin>>B[i];
        }
        
        int maxSum=0;
        if(N>M)
        {
            for(int i=0;i<=(N-M);++i)
            {
                int sum=0;
                for(int j=0;j<M;++j)
                {
                    sum+=A[i+j]*B[j];
                }
                if(sum>maxSum)
                {
                    maxSum=sum;
                }
            }
        }
        else
        {
            for(int i=0;i<=(M-N);++i)
            {
                int sum=0;
                for(int j=0;j<N;++j)
                {
                    sum+=A[j]*B[i+j];
                }
                if(sum>maxSum)
                {
                    maxSum=sum;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<maxSum<<"\n";
	}
	return 0;
}