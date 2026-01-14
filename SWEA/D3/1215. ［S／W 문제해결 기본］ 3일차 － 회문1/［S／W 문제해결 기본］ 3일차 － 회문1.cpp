#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	int test_case=1;
	for(test_case; test_case <= 10; ++test_case)
	{
        int N=0;
        cin>>N;
        string boxs[8]={""};
        for(int i=0;i<8;++i)
        {
            cin>>boxs[i];
        }
        int cnt=0;
        for(int i=0;i<8;++i)
        {
            for(int j=0;j<=8-N;++j)
            {
                string tmp="";
                tmp=boxs[i].substr(j,N);
                string rtmp(tmp.rbegin(),tmp.rend());
                if(tmp==rtmp)
                {
                    cnt++;
                }
            }
        }
        for(int j=0;j<8;++j)
        {
            for(int i=0;i<=8-N;++i)
            {
                string tmp="";
                for(int k=0;k<N;++k)
                {
                    tmp+=boxs[i+k][j];
                }
                string rtmp(tmp.rbegin(),tmp.rend());
                if(tmp==rtmp)
                {
                    cnt++;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}