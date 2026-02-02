#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solution(int testCase) {
    vector<vector<int>> nums(100, vector<int>(100));
    for(int i=0; i<100; ++i) {
        for(int j=0; j<100; ++j) {
            cin>>nums[i][j];
        }
    }
    
    vector<int>sums(202);
    for(int i=0; i<100; ++i) {
        int rowSum = 0;
    	for(int j=0; j<100; ++j) {
            rowSum+=nums[i][j];
            sums[j+100]+=nums[i][j];
            if(i==j) {
            	sums[200]+=nums[i][j];
            }
            if((i+j)==99) {
                sums[201]+=nums[i][j];
            }
        }
        sums[i] = rowSum;
    }
    sort(sums.begin(), sums.end());
    cout<<"#"<<testCase<<" "<<sums[201]<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=1; i<=10; ++i) {
        int testCase = 0;
        cin>>testCase;
        solution(testCase);
    }
    return 0;
}