#include <iostream>
#include <deque>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,M,num;
    int idx, result=0;
    cin>>N>>M;
    deque<int> dq;
    for(int i=1;i<=N;i++) dq.push_back(i);
    while(M--){
        cin>>num;
        for(int i=0;i<dq.size();i++){
            if(dq[i]==num){
                idx=i;
                break;
            }
        }
        if(idx<=dq.size()/2){
            while(dq.front()!=num){
                result++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
        else{
            while(dq.front()!=num){
                result++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.pop_front();
        }
    }
    cout<<result<<"\n";
    return 0;
}