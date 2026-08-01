#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> weightsMap;
    
    for(int& w : weights) {
        ++weightsMap[w];
    }
    
    for(auto wm : weightsMap) {
        long long w = wm.first;
        long long cnt = wm.second;
        
        if(cnt >= 2) {
            answer += ((cnt * (cnt - 1)) / 2);
        }
        if(w * 2 % 3 == 0 && weightsMap.count(w * 2 / 3)) {
            answer += cnt * weightsMap[w * 2 / 3];
        }
        if(weightsMap.count(w * 2)) {
            answer += cnt * weightsMap[w * 2];
        }
        if(w * 3 % 4 == 0 && weightsMap.count(w * 3 / 4)) {
            answer += cnt * weightsMap[w * 3 / 4];
        }
    }
    
    return answer;
}