#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    string num_str;
    cin>>num_str;
    stack<int> S;
    for(char ns:num_str){
        while(!S.empty() && K>0 && S.top()<ns){
            S.pop();
            K--;
        }
        S.push(ns);
    }
    while(K>0){
        S.pop();
        K--;
    }
    string result="";
    while(!S.empty()){
        result+=S.top();
        S.pop();
    }
    reverse(result.begin(),result.end());
    cout<<result<<"\n";
    return 0;
}