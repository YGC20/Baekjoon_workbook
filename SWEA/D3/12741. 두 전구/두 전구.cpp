#include<iostream>
using namespace std;

void solution(int testCase) {
    int nums[4] = {0};
    cin>>nums[0]>>nums[1]>>nums[2]>>nums[3];
    
    int times[101] = {0};
    for(int t = nums[0]; t<nums[1]; ++t) {
        times[t]++;
    }
    for(int t = nums[2]; t<nums[3]; ++t) {
        times[t]++;
    }
    
    int cnt = 0;
    for(int i=0; i<=100; ++i) {
        if(times[i]==2) {
            cnt++;
        }
    }
    cout<<"#"<<testCase<<" "<<cnt<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase;
    if(cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
}