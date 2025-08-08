#include <iostream>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    stack<pair<int,int>> stk;
    for(int i=1;i<=N;i++){
        int height;
        cin>>height;
        while(!stk.empty()&&stk.top().first<height){
            stk.pop();
        }
        if(stk.empty()) cout<<"0 ";
        else cout<<stk.top().second<<" ";
        stk.push({height, i});
    }
    cout<<"\n";
    return 0;
}