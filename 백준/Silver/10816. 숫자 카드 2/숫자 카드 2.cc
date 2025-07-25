#include <iostream>
#include <unordered_map>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,M;
    cin>>N;
    unordered_map<int,int> card_counts;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        card_counts[num]++;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int num;
        cin>>num;
        cout<<card_counts[num]<<" ";
    }
    cout<<"\n";
    return 0;
}