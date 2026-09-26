#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> jobs)
{
    int i, len = static_cast<int>(jobs.size());
    vector<pair<int,int>> order(len);
    for(i=0; i<len; ++i) { order[i] = {jobs[i][0], i}; }
    sort(order.begin(), order.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    long long time = 0, sum = 0;
    int ptr = 0, done = 0;

    while(done < len) {
        while(ptr < len && order[ptr].first <= time) {
            int idx = order[ptr].second;
            pq.push({jobs[idx][1] ,order[ptr].first});
            ptr++;
        }

        if(pq.empty()) {
            time = order[ptr].first;
            continue;
        }
        auto [take, start] = pq.top(); pq.pop();
        time += take;
        sum += time - start;
        done++;
    }
    return sum / len;
}