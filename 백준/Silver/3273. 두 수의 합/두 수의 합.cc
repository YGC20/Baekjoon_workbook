#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,X;
    int arr[100001];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    cin>>X;
    sort(arr,arr+N);
    int start=0, end=N-1, result=0;
    while(start<end){
        int cur_sum=arr[start]+arr[end];
        if(cur_sum==X){
            result++;
            start++;
        }
        else if(cur_sum<X)
            start++;
        else if(cur_sum>X)
            end--;
    }
    cout<<result<<"\n";
    return 0;
}