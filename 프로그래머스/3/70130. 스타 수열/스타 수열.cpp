#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int solution(std::vector<int> a)
{
    int result = 0;
    std::unordered_map<int, int> um;
    for(int& n : a) { um[n]++; }
    for(auto it : um) {
        if(it.second * 2 <= result) { continue; }
        int len = 0;
        for(int i=0; i<a.size()-1; ++i) {
            if(a[i] == a[i+1]) { continue; }
            if(a[i] != it.first && a[i+1] != it.first) { continue; }
            len += 2;
            ++i;
        }
        result = std::max(result, len);
    }
    
    return result;
}