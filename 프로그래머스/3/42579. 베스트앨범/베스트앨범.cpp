#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, int> musicGen;
    map<string, vector<pair<int,int>>> playListMap;
    
    for(int i=0; i<genres.size(); ++i) {
        musicGen[genres[i]] += plays[i];
        playListMap[genres[i]].push_back({plays[i], i});
    }
    vector<pair<string, int>> mg(musicGen.begin(), musicGen.end());
    sort(mg.begin(), mg.end(), [](pair<string, int>& a, pair<string, int>& b){ return a.second > b.second; });
    vector<int> result;
    
    for(int i=0; i<mg.size(); ++i) {
        string genre = mg[i].first;
        if(playListMap.find(genre) != playListMap.end()) {
            sort(playListMap[genre].begin(), playListMap[genre].end(), [](pair<int, int> a, pair<int, int> b){ if(a.first == b.first) return a.second < b.second; return a.first > b.first; });
            
            result.push_back(playListMap[genre][0].second);
            
            if(playListMap[genre].size() >= 2)
                result.push_back(playListMap[genre][1].second);
        }
    }
    
    return result;
}