#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, x, y, i;
    vector<pair<int, int>> coordinate;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>x>>y;
        coordinate.push_back({x,y});
    }
    sort(coordinate.begin(),coordinate.end());
    for(i=0;i<N;i++){
        cout<<coordinate[i].first<<" "<<coordinate[i].second<<"\n";
    }
    return 0;
}