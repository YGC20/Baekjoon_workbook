#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    vector<int> tangSize(10000001,0);
    for(auto t:tangerine) tangSize[t]++;
    sort(tangSize.rbegin(),tangSize.rend());
    int answer = 0;
    for(auto ts:tangSize){
        if(k<=0) break;
        k-=ts;
        answer++;
    }
    return answer;
}