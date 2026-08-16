#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    
    vector<pair<int, int>> score(N+2, {0,0});
    vector<pair<int, double>> failure;
    
    for(auto& n : stages) {
        score[n].first++;
        for(int i=1; i<=n; ++i) {
            score[i].second++;
        }
    }
    
    for(int i=1; i<=N; ++i) {
        if(score[i].second == 0) { failure.push_back({i, 0.0}); }
        else { 
            failure.push_back({i, (((double)score[i].first) / score[i].second)});
        }
    }
    
    sort(failure.begin(), failure.end(), [](const auto& a, const auto& b){
        if(a.second == b.second) { return a.first < b.first; }
        else { return a.second > b.second; }
    });
    
    for(auto& f : failure) {
        answer.push_back(f.first);
    }
    return answer;
}