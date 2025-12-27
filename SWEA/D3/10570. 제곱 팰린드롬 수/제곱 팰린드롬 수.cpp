#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int TC;	cin>>TC;
	for(test_case = 1; test_case <= TC; ++test_case) {
        int A,B; cin>>A>>B;
        int boxs[5]={1,4,9,121,484};
        int cnt=0;
        for(int i=0;i<5;++i) {
            if(boxs[i]>=A && boxs[i]<=B)
                cnt++;
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}