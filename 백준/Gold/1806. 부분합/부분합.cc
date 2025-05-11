#include <iostream>
using namespace std;
void partialSum(void){
    int N, S;
    cin>>N>>S;
    int nums[N];
    for(int i=0;i<N;i++)
        cin>>nums[i];
    int start=0, end=0, sum=0, minLen=N+1;
    while(true){
        if(sum>=S){
            minLen=min(minLen, end-start);
            sum-=nums[start++];
        }
        else if(end==N) break;
        else sum+=nums[end++];
    }
    if(minLen==N+1) cout<<"0\n";
    else cout<<minLen<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    partialSum();
    return 0;
}