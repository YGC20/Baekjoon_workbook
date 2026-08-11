#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int from, to, cost;
    Node(int f, int t, int c) : from(f), to(t), cost(c) {}
    bool operator<(const Node n) const { return this->cost > n.cost; }
};

int solution(int N, vector<vector<int> > road, int K)
{
    int i;
    int answer = 0;
    int from, to, cost;
    vector<vector<int>> routes(N+1, vector<int>(N+1, 10000010));
    for(auto& r : road) {
        from = r[0]; to = r[1]; cost = r[2];
        if(cost < routes[from][to]) {
            routes[from][to] = cost;
            routes[to][from] = cost;
        }
    }
    
    vector<int> routeCost(N+1, 10000010);
    priority_queue<Node> pq;
    routeCost[0] = routeCost[1] = 0;
    pq.push((Node){1,1,0});
    
    while(!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        from = curr.to; cost = curr.cost;
        if(cost > routeCost[from]) continue;
        cout << curr.from << ", " << curr.to << ", " << curr.cost << endl;
        for(i=1; i<=N; ++i) {
            if(routes[from][i] != 0) {
                int nextCost = cost + routes[from][i];
                if(nextCost < routeCost[i]) {
                    routeCost[i] = nextCost;
                    pq.push((Node){from,i,nextCost});
                }
            }
        }
    }
    
    for(auto& rc : routeCost) {
        if(rc <= K) {
            ++answer;
        }
    }
    answer--;
    return answer;
}