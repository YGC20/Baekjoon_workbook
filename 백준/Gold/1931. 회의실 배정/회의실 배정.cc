#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
void conferenceRooms(void){
    int N, lastEnd=0, count=0;
    cin>>N;
    vector<pair<int, int>> conf(N);
    for(int i=0;i<N;i++) cin>>conf[i].first>>conf[i].second;
    sort(conf.begin(), conf.end(), compare);
    for(int i=0;i<N;i++) if(conf[i].first>=lastEnd){
        count++;
        lastEnd=conf[i].second;
    }
    cout<<count<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    conferenceRooms();
    return 0;
}