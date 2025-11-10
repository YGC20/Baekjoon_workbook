#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> user(n,1);
    for(auto l:lost) user[l-1]--;
    for(auto r:reserve) user[r-1]++;
    for(int i=0;i<n;++i){
        if(user[i]==0){
            if(0<=(i-1) && user[i-1]==2){
                user[i-1]--;
                user[i]++;
            }
            else if((i+1)<n && user[i+1]==2){
                user[i+1]--;
                user[i]++;
            }
        }
    }
    int cnt = 0;
    for(auto u:user) if(u>=1) cnt++;
    return cnt;
}