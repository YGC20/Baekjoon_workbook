#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    
    int ans = 0;
    for(auto nl : num_list) {
        int tmp = nl, cnt = 0;
        while(tmp>1) {
            if(tmp%2==0)
                tmp/=2;
            else
                tmp = (tmp-1)/2;
            cnt++;
        }
        ans+=cnt;
    }
    
    return ans;
}