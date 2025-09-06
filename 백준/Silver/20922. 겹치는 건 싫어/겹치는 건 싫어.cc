#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int seq[200001];
    for(int i=0;i<N;++i)    cin>>seq[i];
    int ans[100001]={0};
    int l=0,max_len=0;
    for(int r=0;r<N;++r){
        ans[seq[r]]++;
        while(ans[seq[r]]>K){
            ans[seq[l]]--;
            l++;
        }
        max_len=max(max_len,r-l+1);
    }
    cout<<max_len<<"\n";
    return 0;
}