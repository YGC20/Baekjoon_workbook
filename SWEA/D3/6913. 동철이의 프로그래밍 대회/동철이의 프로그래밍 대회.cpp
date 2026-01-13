#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        cin>>N>>M;
        int max_cnt=0;
        int users[N]={0};
        for(int i=0;i<N;++i)
        {
            int cnt=0;
            for(int j=0;j<M;++j)
            {
                int tmp=0;
                cin>>tmp;
                if(tmp==1)
                {
                    cnt++;
                }
            }
            users[i]=cnt;
            if(cnt>max_cnt)
            {
                max_cnt=cnt;
            }
        }
        int user_cnt=0;
        for(int i=0;i<N;++i)
        {
            if(users[i]==max_cnt)
            {
                user_cnt++;
            }
        }
        cout<<"#"<<test_case<<" "<<user_cnt<<" "<<max_cnt<<"\n";
	}
	return 0;
}