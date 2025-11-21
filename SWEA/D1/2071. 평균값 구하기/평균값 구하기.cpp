#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int sum = 0;
        for(int i=0;i<10;++i){
            int tmp; cin>>tmp;
            sum+=tmp;
        }
        int avg = (sum/10)+((sum%10>=5)?1:0);
        cout<<"#"<<test_case<<" "<<avg<<"\n";
	}
	return 0;
}