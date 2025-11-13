#include <bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> LRUCache;
    if(cacheSize==0) return (int)cities.size()*5;
    for(auto &city:cities)
        for(char &c:city) c = tolower(c);
    for(auto city:cities){
        auto isCity = find(LRUCache.begin(), LRUCache.end(),city);
        if(isCity!=LRUCache.end()){
            answer+=1;
            LRUCache.splice(LRUCache.end(),LRUCache, isCity);
        }
        else{
            answer+=5;
            if(LRUCache.size()<cacheSize){
                LRUCache.push_back(city);
            }
            else{
                LRUCache.pop_front();
                LRUCache.push_back(city);
            }
        }
    }
    return answer;
}