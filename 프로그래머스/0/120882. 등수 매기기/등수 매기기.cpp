#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<pair<int, int>> rank;
    for(int i=0; i<score.size(); i++) {
        int avg = score[i][0]+score[i][1];
        rank.push_back({1, avg});
        
        for(int j=0; j<i; j++) {
            if(rank[j].second < avg) rank[j].first++;
            else if(rank[j].second > avg) rank[i].first++;
        }
    }
    
    vector<int> result;
    for(auto r : rank) {
        result.push_back(r.first);
    }
    return result;
}