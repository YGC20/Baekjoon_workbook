#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> rope;
    for(int i=0;i<N;++i){
        int num;
        cin>>num;
        rope.push_back(num);
    }
    sort(rope.begin(),rope.end());
    int max_rope=0;
    for(int i=0;i<N;++i){
        int rope_len=rope[i]*(N-i);
        max_rope=max(max_rope,rope_len);
    }
    cout<<max_rope<<"\n";
    return 0;
}