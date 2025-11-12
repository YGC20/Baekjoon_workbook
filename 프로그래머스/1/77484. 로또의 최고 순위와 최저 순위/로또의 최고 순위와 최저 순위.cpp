#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int win = 0, zeroCnt = 0;
    for(auto l:lottos){
        if(l==0) zeroCnt++;
        else{
            for(auto wn:win_nums){
                if(wn>l) break;
                else if(wn==l) win++;
            }
        }
    }
    return {(7-(win+zeroCnt))>6?6:(7-(win+zeroCnt)),(7-win)>6?6:(7-win)};
}