#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string nums;
int cnt, maxResult;
bool visited[11][1000000];

void dfs(int currentCnt) {
    if(cnt == currentCnt) {
        maxResult = max(maxResult, stoi(nums));
        return;
    }
    
    int currentVal = stoi(nums);
    if(visited[currentCnt][currentVal]) return;
    visited[currentCnt][currentVal] = true;
    
    for(int i=0; i<nums.length() -1; ++i) {
        for(int j=i+1; j<nums.length(); ++j) {
            swap(nums[i], nums[j]);
            dfs(currentCnt+1);
            swap(nums[i], nums[j]);
        }
    }
}

void solution(int testCase) {
    cin>>nums>>cnt;
    maxResult = 0;
    memset(visited, false, sizeof(visited));
    dfs(0);
    cout<<"#"<<testCase<<" "<<maxResult<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase;
    if(cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
    
    return 0;
}