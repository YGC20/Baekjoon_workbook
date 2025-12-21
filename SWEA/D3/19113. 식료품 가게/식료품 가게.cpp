#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int TC;	cin>>TC;
	for(test_case = 1; test_case <= TC; ++test_case)	{
		int N; cin>>N;
        vector<long long> prices(2*N);
        vector<long long> dcp;
        for(int i=0;i<2*N;++i)
            cin>>prices[i];
        queue<long long> stk;
        for(int i=0;i<2*N;++i) {
            if(!stk.empty()) {
            	long long tmp = stk.front();
                if(prices[i]==tmp*4/3) {
                    stk.pop();
                    dcp.push_back(tmp);
                }
                else
                    stk.push(prices[i]);
            }
            else
                stk.push(prices[i]);
        }
        cout<<"#"<<test_case<<" ";
        for(auto p:dcp)
            cout<<p<<" ";
        cout<<"\n";
	}
	return 0;
}