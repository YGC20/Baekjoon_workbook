#include <iostream>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> sequ(N);
    for(int i=0;i<N;i++)
        cin>>sequ[i];
    vector<int> stack;
    vector<char> result;
    int cur=1, idx=0;
    while(idx<N){
        if(!stack.empty()&&stack.back()==sequ[idx]){
            stack.pop_back();
            result.push_back('-');
            idx++;
        }else if(cur<=N){
            stack.push_back(cur++);
            result.push_back('+');
        }else{
            cout<<"NO\n";
            return 0;
        }
    }
    for(char c:result){
        cout<<c<<"\n";
    }
    return 0;
}