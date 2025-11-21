#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
    vector<int> score;
	for(test_case = 1; test_case <= T; ++test_case)	{
        int num; cin>>num;
        score.push_back(num);
	}
    sort(score.begin(),score.end());
    cout<<score[T/2]<<"\n";
	return 0;
}