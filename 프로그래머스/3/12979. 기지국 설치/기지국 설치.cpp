#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int cnt = 0;
    int start, end, left = 1;
    double cover = 2 * w + 1;
    for(int stat : stations) {
        start = stat - w;
        end = stat + w;
        
        if(left<start) {
            int num = start - left;
            cnt += ceil(num / cover);
        }
        left = end + 1;
    }
    if(left<=n) {
        int num = n - left + 1;
        cnt += ceil(num / cover);
    }
    
    return cnt;
}