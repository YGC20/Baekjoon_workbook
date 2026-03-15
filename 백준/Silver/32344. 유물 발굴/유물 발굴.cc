#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_VAL = 100001;

struct Relic {
    int min_x = MAX_VAL, max_x = 0;
    int min_y = MAX_VAL, max_y = 0;
    bool visited = false;
};

Relic relics[MAX_VAL];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin>>r>>c;
    int n;
    cin>>n;
    
    for(int i=0; i<n; ++i) {
        int num, x, y;
        cin>>num>>x>>y;
        
        relics[num].visited = true;
        relics[num].min_x = min(relics[num].min_x, x);
        relics[num].max_x = max(relics[num].max_x, x);
        relics[num].min_y = min(relics[num].min_y, y);
        relics[num].max_y = max(relics[num].max_y, y);
    }

    vector<pair<int,ll>> pos;
    for(int i=0; i<MAX_VAL; ++i) {
        if(relics[i].visited) {
            ll size = (ll)(relics[i].max_x-relics[i].min_x+1)*(ll)(relics[i].max_y-relics[i].min_y+1);
            pos.push_back({i,size});
        }
    }
    sort(pos.begin(),pos.end(),[](const pair<int,ll>& a, const pair<int,ll>& b){ 
        if(a.second!=b.second) return a.second>b.second; 
        return a.first<b.first;
    });
    cout<<pos[0].first<<" "<<pos[0].second<<"\n";
    return 0;
}