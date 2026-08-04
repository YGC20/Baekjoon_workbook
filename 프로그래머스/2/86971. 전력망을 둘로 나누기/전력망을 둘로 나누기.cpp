#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    int i, j;
    int result = 110;
    vector<vector<int>> nodes(n+1);
    for(auto& w : wires) {
        nodes[w[0]].push_back(w[1]);
        nodes[w[1]].push_back(w[0]);
    }
    
    for(i=0; i<wires.size(); ++i) {
        int to = wires[i][0], from = wires[i][1];
        int cnt = 0;
        vector<int> wireCnt;
        vector<bool> visited(n+1, false);
        for(j=1; j<=n; ++j) {
            if(!visited[j]) {
                stack<int> stk;
                stk.push(j);
                while(!stk.empty()) {
                    int curr = stk.top(); stk.pop(); cnt++;
                    visited[curr] = true;
                    for(auto n : nodes[curr]) {
                        if((to == curr && from == n) ||
                           (to == n && from == curr) ||
                          visited[n]) { continue; }
                        stk.push(n);
                    }
                }
                break;
            }
        }
        int diff = abs(cnt-(n-cnt));
        if(result > diff) {
            result = diff;
        }
    }
    return result;
}