#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;
};

int main(int argc, char** argv)
{
	int T, N; cin>>T;
    for(int tc=1; tc<=T; ++tc) {
        cin>>N;
        
        int i;
        vector<bool> visited(N, false);
        vector<Node> nodes(N, (Node){0,0});
        for(i=0; i<N; ++i) { cin>>nodes[i].x; }
        for(i=0; i<N; ++i) { cin>>nodes[i].y; }
        
        double E; cin >> E;
        
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(i=1; i<N; ++i) {
           	long long xlen = nodes[0].x - nodes[i].x;
            long long ylen = nodes[0].y - nodes[i].y;
            long long len = xlen*xlen + ylen*ylen;
            pq.push({ len, i });
        }
        visited[0] = true;
        
        long long sum = 0;
        while(!pq.empty()) {
            int curr = pq.top().second;
            long long clen = pq.top().first;
            pq.pop();
            
            if(visited[curr]) { continue; }
            sum += clen;
            visited[curr] = true;
            for(i=0; i<N; ++i) {
                if(visited[i]) { continue; }
                long long xlen = nodes[curr].x - nodes[i].x;
                long long ylen = nodes[curr].y - nodes[i].y;
                long long len = xlen*xlen + ylen*ylen;
                pq.push({ len, i });
            }
        }
        
        cout << "#" << tc << " " << (long long)round(sum * E) << endl;
    } /* for tc T */
    return 0;
}