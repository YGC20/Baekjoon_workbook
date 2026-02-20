#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> nums(7);
    nums[a]++; nums[b]++; nums[c]++; nums[d]++;
    
    vector<vector<int>> freq(5);
    for(int i=1; i<7; ++i) {
        freq[nums[i]].push_back(i);
    }
    
    if(!freq[4].empty()) {
        return (freq[4][0] * 1111);
    }
    else if(!freq[3].empty()) {
        return ((10 * freq[3][0] + freq[1][0]) * (10 * freq[3][0] + freq[1][0]));
    }
    else if(!freq[2].empty()) {
        if(freq[2].size()!=2) {
            return (freq[1][0] * freq[1][1]);
        }
        else {
            return ((freq[2][1] + freq[2][0]) * (freq[2][1] - freq[2][0]));
        }
    }
    else if(!freq[1].empty()) {
        return (freq[1][0]);
    }
}