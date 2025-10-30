#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int h = 0;
    sort(citations.begin(),citations.end());
    for(size_t i=0;i<citations.size();++i){
        h = (int)(citations.size() - i);
        if(citations[i]>=h)
            return h;
    }
    return 0;
}