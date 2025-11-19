#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<limits>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
const int INF = numeric_limits<int>::max();
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin>>n;
        vector<string> maps(n);
        for(int i=0;i<n;++i){
            string tmp; cin>>tmp;
            maps[i] = tmp;
		}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(n,INF));
        dist[0][0] = maps[0][0]-'0'; pq.push({dist[0][0],{0,0}});
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
			pq.pop();
            if(cost>dist[x][y]) continue;
            for(int i=0;i<4;++i){
            	int nx = x+dx[i];
                int ny = y+dy[i];
                if((0<=nx&&nx<n) && (0<=ny&&ny<n)){
                    int newCost = dist[x][y]+(maps[nx][ny]-'0');
                    if(newCost<dist[nx][ny]){
                        dist[nx][ny] = newCost;
                    	pq.push({newCost,{nx,ny}});
                    }
                }
            }
        }
       cout<<"#"<<test_case<<" "<<dist[n-1][n-1]<<"\n";                                                                             
	}
	return 0;
}