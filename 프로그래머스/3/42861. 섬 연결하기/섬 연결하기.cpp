#include <string>
#include <vector>
#include <queue>
using namespace std;

auto comp = [](const pair<int,int>& a, const pair<int,int>& b){return a.second > b.second; };

int solution(int n, vector<vector<int>> costs)
{
    int from, to, cost;
    vector<vector<pair<int,int>>> costMap(n);
    for(auto& c : costs) {
        from = c[0]; to = c[1]; cost = c[2];
        costMap[from].push_back({to, cost});
        costMap[to].push_back({from, cost});
    }
    
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
    visited[0] = true;
    for(auto& cm0 : costMap[0]) {
        pq.push(cm0);
    }
    
    int result = 0;
    while(!pq.empty()) {
        to = pq.top().first;
        cost = pq.top().second;
        pq.pop();
        
        if(!visited[to]) {
            visited[to] = true;
            result += cost;
            for(auto& cm : costMap[to]) {
                pq.push(cm);
            }
        }
    }
    return result;
}