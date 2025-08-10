#include <iostream>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    int numArray[1000001], result[1000001];
    stack<int> s;
    for(int i=0;i<N;i++){
        cin>>numArray[i];
        result[i]=-1;
    }
    for(int i=0;i<N;i++){
        while(!s.empty()&&numArray[s.top()]<numArray[i]){
            result[s.top()]=numArray[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i=0;i<N;i++) cout<<result[i]<<" ";
    cout<<"\n";
    return 0;
}