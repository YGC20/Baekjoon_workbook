#include <iostream>
using namespace std;
int K,N,longest=0;
long long lans[10001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>K>>N;
    long long lan;
    for(int i=0;i<K;i++){
        cin>>lan;
        if(lan>longest) longest=lan;
        lans[i]=lan;
    }
    long long start=1;
    long long end=longest;
    long long result=0;
    while(start<=end){
        long long mid = start+(end-start)/2;
        int lanCount=0;

        if(mid==0) mid=1;
        for(int i=0;i<K;i++)
            lanCount+=lans[i]/mid;
        if(lanCount>=N){
            result=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    cout<<result<<"\n";
    return 0;
}