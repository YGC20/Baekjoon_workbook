#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int N; cin>>N;
        vector<bool> row(N,0);
        for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j) {
                int tmp; cin>>tmp;
                if(i==0) {
                    if(j+1==tmp) row[j] = true;
                    else row[j] = false;
                }
		} }
        int cnt = 0;
		for(int i=N-1;i>=0;--i) {
            if(!row[i]) {
                for(int j=1;j<N;++j)
                    row[j] = !row[j];
                cnt++;
            }
        }
        cout<<cnt<<"\n";
	}
	return 0;
}