#include <iostream>
#include <queue>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int N,M;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            int num;
            cin>>num;
            q.push({i,num});
            pq.push(num);
        }
        int count=0;
        while(!q.empty()){
            int curIndex=q.front().first;
            int curData=q.front().second;
            int curPrio=pq.top();
            q.pop();
            if(curData>=curPrio){
                count++;
                pq.pop();
                if(curIndex==M) break;
            }
            else{
                q.push({curIndex,curData});
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}