#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int boxs[3];
        for(int i=0;i<3;++i)
            cin>>boxs[i];
        int cnt=0, flag=0;
        for(int i=1;i>=0;--i) {
            if(boxs[i+1]<=boxs[i]) {
                int eat = boxs[i]-(boxs[i+1]-1);
                cnt+=eat;
                boxs[i]-=eat;
                if(boxs[i]<=0) {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"#"<<test_case<<" -1\n";
        else
            cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}