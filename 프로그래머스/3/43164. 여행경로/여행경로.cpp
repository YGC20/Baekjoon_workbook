#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool DFS(string dist, vector<vector<string>> ticket, vector<string>& answer, vector<bool>& visited, int idx)
{
    answer.push_back(dist);
    if(idx == ticket.size()) return true;
    
    for(int i=0; i<ticket.size(); i++) {
        if(ticket[i][0]==dist && visited[i]==false) {
            visited[i]=true;
            bool check = DFS(ticket[i][1], ticket, answer, visited, idx+1);
            if(check) return true;
            visited[i]=false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, answer, visited, 0);
    return answer;
}