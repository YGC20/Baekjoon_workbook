#include <string>
#include <vector>
using namespace std;

void gate(vector<vector<int>>& dungeons, vector<bool>& visited, int hp, int count, int& result)
{
    if(result < count) { result = count; }
    
    for(int i=0; i<dungeons.size(); ++i) {
        int need = dungeons[i][0], cost = dungeons[i][1];
        if(visited[i] || hp < need) { continue; }
        visited[i] = true;
        gate(dungeons, visited, hp - cost, count + 1, result);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    gate(dungeons, visited, k, 0, answer);
    return answer;
}