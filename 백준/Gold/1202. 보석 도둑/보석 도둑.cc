#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void jewelThief(void){
    int N, K;
    vector<pair<int, int>> jewels;
    vector<int> bagpack;
    cin>>N>>K;
    int M, V, C;
    for(int i=0; i<N; i++){
        cin>>M>>V;
        jewels.push_back({M, V});
    }
    for(int i=0; i<K; i++){
        cin>>C;
        bagpack.push_back(C);
    }

    priority_queue<int> pq;
    sort(jewels.begin(), jewels.end());
    sort(bagpack.begin(), bagpack.end());

    long long result = 0;
    int index = 0;
    for(int i=0; i<K; i++){
        int weight = bagpack[i];
        for(int j=index; j<N; j++){
            int M = jewels[j].first;
            int V = jewels[j].second;

            if(M <= weight){
                pq.push(V);
                index++;
            }
            else{
                break;
            }
        }
        if(!pq.empty()){
            result+=pq.top();
            pq.pop();
        }
    }

    cout<<result<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    jewelThief();
    return 0;
}