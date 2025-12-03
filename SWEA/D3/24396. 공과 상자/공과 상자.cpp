#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int B,W,X,Y,Z; cin>>B>>W>>X>>Y>>Z;
        vector<int> answer;
        int bw = (B<W)?B:W;
        for(int i=0;i<=bw;++i) {
            answer.push_back(((B-i)*X)+((W-i)*Y)+((2*i)*Z));
        }
        sort(answer.rbegin(),answer.rend());
        cout<<answer.front()<<"\n";
	}
	return 0;
}