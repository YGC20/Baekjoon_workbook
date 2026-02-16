#include <iostream>
#include <vector>
#include <algorithm>

int max_path_length;

void dfs(int current_node, int current_length, std::vector<bool>& visited, const std::vector<std::vector<int>>& maps, int N)
{
    max_path_length = std::max(max_path_length, current_length);
    visited[current_node] = true;

    for(int next_node=1; next_node<=N; ++next_node) {
        if(maps[current_node][next_node]==1 && !visited[next_node]) {
            dfs(next_node, current_length+1, visited, maps, N);
        }
    }
    visited[current_node] = false;
}

void solution(int test_case)
{
    max_path_length = 1;

    int node, route;
    std::cin>>node>>route;

    std::vector<std::vector<int>> maps(node+1, std::vector<int>(node+1, 0));
    for(int i=0; i<route; ++i) {
        int begin, arrive;
        std::cin>>begin>>arrive;
        maps[begin][arrive] = 1;
        maps[arrive][begin] = 1;
    }

    for(int start_node=1; start_node<=node; ++start_node) {
        std::vector<bool> visited(node+1, false);
        dfs(start_node, 1, visited, maps, node);
    }

    if(node==0) {
        max_path_length = 0;
    }
    else if(node>0 && route==0) {
        max_path_length = 1;
    }
    
    std::cout<<"#"<<test_case<<" "<<max_path_length<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case;
    if(std::cin>>test_case) {
        for(int i=1; i<=test_case; ++i) {
            solution(i);
        }
    }
    return 0;
}