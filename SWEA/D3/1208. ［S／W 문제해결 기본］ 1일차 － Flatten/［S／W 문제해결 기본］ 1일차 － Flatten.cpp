#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
    for(test_case = 1; test_case <= 10; ++test_case) {
        int dump; cin>>dump;
        vector<int> cargo(100);
        for(int i=0;i<100;++i)
            cin>>cargo[i];
        sort(cargo.begin(),cargo.end());
        int left = 0, right = 99;
        for(int i=0; i<dump; ++i)	{
            cargo[left]++; cargo[right]--;
            sort(cargo.begin(),cargo.end());
        }
        cout<<"#"<<test_case<<" "<<cargo[right]-cargo[left]<<"\n";
    }
	return 0;
}