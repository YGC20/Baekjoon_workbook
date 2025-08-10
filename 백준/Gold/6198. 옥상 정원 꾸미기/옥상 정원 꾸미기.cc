#include <iostream>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    long long count=0;
    int building[80001];
    stack<int> s;
    for(int i=0;i<N;i++) cin>>building[i];
    for(int i=0;i<N;i++){
        while(!s.empty()&&building[s.top()]<=building[i]){
            s.pop();
        }
        count+=s.size();
        s.push(i);
    }
    cout<<count<<"\n";
    return 0;
}