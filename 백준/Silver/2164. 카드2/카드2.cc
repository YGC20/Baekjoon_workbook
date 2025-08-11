#include <iostream>
#include <queue>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    queue<int> q;
    for(int i=1;i<=N;i++) q.push(i);
    bool flag=true;
    while(q.size()>1){
        int num=q.front();
        q.pop();
        if(flag) flag=false;
        else{
            q.push(num);
            flag=true;
        }
    }
    cout<<q.front()<<"\n";
    return 0;
}