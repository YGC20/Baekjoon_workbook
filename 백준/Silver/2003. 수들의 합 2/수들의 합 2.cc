#include <iostream>
using namespace std;
void numSum(void){
    int N, M, count=0;
    cin>>N>>M;
    int nums[N];
    for(int i=0;i<N;i++)
        cin>>nums[i];
    int start=0, end=0, sum=0;
    while(true){
        if(sum>=M) sum-=nums[start++];
        else if(end==N) break;
        else sum+=nums[end++];
        if(sum==M) count++;
    }
    cout<<count<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    numSum();
    return 0;
}