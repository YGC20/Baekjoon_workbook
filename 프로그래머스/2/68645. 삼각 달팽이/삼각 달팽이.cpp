#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> snail(n);
    for(int i=0;i<n;++i) snail[i].resize(i+1,0);
    
    int maxSnail = (n*(n+1))/2;
    int x = -1, y = 0, val = 1;
    for(int len=n;len>0;len-=3){
        for(int i=0;i<len;++i) snail[++x][y] = val++;
        for(int i=0;i<len-1;++i) snail[x][++y] = val++;
        for(int i=0;i<len-2;++i) snail[--x][--y] = val++;
    }
    vector<int> result;
    for(auto &s:snail)
        result.insert(result.end(),s.begin(),s.end());
    return result;
}