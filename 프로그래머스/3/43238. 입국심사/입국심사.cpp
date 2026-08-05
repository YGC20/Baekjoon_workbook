#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    ll result = 0;
    ll left = times[0];
    ll right = (ll)n * times[times.size() - 1];
    ll mid, cnt;
    
    while(left <= right) {
        mid = left + (right - left) / 2;
        cnt = 0;
        for(auto& t : times) {
            cnt += (mid / t);
            if(cnt >= n) { break; }
        }
        
        if(cnt >= n) {
            result = mid;
            right = mid - 1;
        } else if(cnt < n) { left = mid + 1; }
    }
    return result;
}