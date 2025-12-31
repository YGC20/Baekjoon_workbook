#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n; cin>>n;
        int div[5]={2,3,5,7,11};
        int num[5]={0};
        for(int i=0;i<5;++i) {
            int cnt=0;
            while(n%div[i]==0) {
                cnt++;
                n/=div[i];
            }
            num[i]=cnt;
        }
        cout<<"#"<<test_case<<" ";
        for(int i=0;i<5;++i) {
            cout<<num[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}