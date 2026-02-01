#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>

void solution(int testCase) {
    long long N, K;
    std::cin>>N>>K;
    
    std::string nums;
    std::cin>>nums;
    std::set<long long, std::greater<long long>> uniqueNum;
    int sideLen = N/4;
    for(int r=0; r<sideLen; ++r) {
        for(int i=0; i<4; ++i) {
            std::string hexStr = nums.substr(i*sideLen, sideLen);
            uniqueNum.insert(stoll(hexStr,nullptr,16));
        }
        char last = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), last);
    }
    auto it = uniqueNum.begin();
    advance(it, K-1);
    
    std::cout<<"#"<<testCase<<" "<<*it<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int testCase;
    if(std::cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
    
    return 0;
}