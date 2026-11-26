#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<pair<int,int>> xy;
    for(int i=0; i<N; ++i) {
        int x, y; cin >> x >> y;
        xy.push_back({x, y});
    }

    sort(xy.begin(), xy.end(), [](const auto& a, const auto& b){
        if(a.second == b.second) { return a.first < b.first; }
        return a.second < b.second;
    });

    for(auto& _ : xy) {
        cout << _.first << " " << _.second << "\n";
    }
    return 0;
}