#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int K; cin>>K;
        int m=pow(2,K);
        int tms=0;
        vector<int> A(m);
        for(int i=0;i<m;++i)
            cin>>A[i];
        for(int i=0;i<K;++i)
        {
            int j=0;
            m/=2;
            while(j<m)
            {
                tms+=abs(A[j]-A[j+1]);
                int idx=(A[j]<A[j+1]?j:j+1);
                A.erase(A.begin()+idx);
                j++;
            }
        }
        cout<<"#"<<test_case<<" "<<tms<<"\n";
    }
	return 0;
}