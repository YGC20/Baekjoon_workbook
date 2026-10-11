#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);
    
    queue<int> que;
    
    for(int i=0; i<n; ++i) {
        if(visited[i]) { continue; }
        que.push(i);
        visited[i] = true;
        
        while(!que.empty()) {
            int cn = que.front(); que.pop();
            for(int com=0; com<n; ++com) {
                if(com == cn) { continue; }
                if(computers[cn][com] && !visited[com]) {
                    visited[com] = true;
                    que.push(com);
                }
            }
        }
        answer++;
    }
    
    return answer;
}