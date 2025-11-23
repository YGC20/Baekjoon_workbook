#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        int bigNum = 0;
		for(int i=0;i<10;++i) {
            int tmp; cin>>tmp;
            if(tmp>bigNum) bigNum = tmp;
        }
        cout<<"#"<<test_case<<" "<<bigNum<<"\n";
	}
	return 0;
}