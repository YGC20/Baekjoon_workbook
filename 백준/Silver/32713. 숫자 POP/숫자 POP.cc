#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if(!(cin>>n>>k)) {
        return 0;
    }

    map<int, vector<int>> position;
    for(int i=0; i<n; ++i) {
        int num;
        cin>>num;
        position[num].push_back(i);
    }

    int max_cnt = 0;
    for(auto const& [num, pos] : position) {
        int left = 0;
        for(int right=0; right<pos.size(); ++right) {
            while((pos[right]-pos[left])-(right-left)>k) {
                left++;
            }
            max_cnt = max(max_cnt, right-left+1);
        }
    }

    cout<<max_cnt<<"\n";
    return 0;
}