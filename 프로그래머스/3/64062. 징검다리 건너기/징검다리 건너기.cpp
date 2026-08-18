#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> stones, int k)
{
    int minInt = 1e9;
    int len = stones.size();

    deque<int> dq;
    for(int i=0; i<len; ++i) {
        if(!dq.empty() && dq.front() < (i-k+1)) { dq.pop_front(); }
        while(!dq.empty() && stones[dq.back()] < stones[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1) {
            if(minInt > stones[dq.front()]) { minInt = stones[dq.front()]; }
        }
    }
    return minInt;
}