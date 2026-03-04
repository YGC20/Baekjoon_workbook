#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& internet, vector<int>& visited)
{
    visited[node] = true;
    for(int com : internet[node]) {
        if(!visited[com]) {
            dfs(com, internet, visited);
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int computer_number;
    cin>>computer_number;
    int linker;
    cin>>linker;
    
    vector<vector<int>> internet(computer_number+1);
    for(int i=0; i<linker; ++i) {
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        internet[tmp1].push_back(tmp2);
        internet[tmp2].push_back(tmp1);
    }

    int cnt = 0;
    vector<int> visited(computer_number+1, false);
    dfs(1, internet, visited);
    
    for(bool vis : visited) {
        if(vis) {
            cnt++;
        }
    }
    cout<<cnt-1<<"\n";
    return 0;
}