#include <iostream>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    stack<int> S;
    while(N--){
        int num;
        cin>>num;
        S.push(num);
    }
    int count=0, max=0;
    while(!S.empty()){
        if(S.top()>max){
            max=S.top();
            count++;
        }
        S.pop();
    }
    cout<<count<<"\n";
    return 0;
}