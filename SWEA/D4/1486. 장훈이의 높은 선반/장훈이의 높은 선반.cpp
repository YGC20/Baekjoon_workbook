#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B, len;
int minGap;
vector<int> nums;

void bt(int sum, int idx)
{
    if(idx > len) { return; }
    if(sum >= B) {
        minGap = min(minGap, (sum-B));
        return;
    }
    bt(sum+nums[idx], idx+1);
    bt(sum, idx+1);
}

int main(int argc, char** argv)
{
    int T; cin>>T;
    for(int tc=1; tc<=T; ++tc) {
        minGap = 1e9;
        cin>>N>>B;
        nums.assign(N, 0);
        for(int i=0; i<N; ++i) { cin>>nums[i]; }
        len = static_cast<int>(nums.size());
        bt(0,0);
        cout << "#" << tc << " " << minGap << endl;
    } /* for tc T*/
    return 0;
}