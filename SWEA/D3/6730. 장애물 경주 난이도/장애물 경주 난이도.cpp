#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        int hurdles[N]={0};
        for(int i=0;i<N;++i)
        {
            cin>>hurdles[i];
        }
        int upH=0, downH=0;
        for(int i=0;i<N-1;++i)
        {
            int tmp = hurdles[i]-hurdles[i+1];
            if(tmp<0 && upH<-tmp)
                upH=-tmp;
            else if(tmp>0 && downH<tmp)
                downH=tmp;
        }
        cout<<"#"<<test_case<<" "<<upH<<" "<<downH<<"\n";
	}
	return 0;
}