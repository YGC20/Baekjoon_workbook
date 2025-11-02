#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    int arr[1000] = {0};
    int idx = 0;
    int val = 1;
    while(idx<1000){
        for(int i=idx;i<idx+val && i<1000;++i)
            arr[i] = val;
        idx += val;
        val++;
    }
    int sum = 0;
    for(int i=a-1;i<b;++i){
        sum += arr[i];
    }
    cout<<sum<<"\n";
    return 0;
}