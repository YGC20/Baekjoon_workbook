/**
 * 백준 문제 풀이
 * 25576 : 찾았다 악질
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<int> user(m);
    vector<int> streamers(n-1);
    for(int i=0; i<m; ++i) {
        cin>>user[i];
    }

    for(int i=0; i<(n-1); ++i) {
        for(int j=0; j<m; ++j) {
            int tmp;
            cin>>tmp;
            streamers[i]+=abs(user[j]-tmp);
        }
    }

    int cnt = 0;
    for(int i=0; i<(n-1); ++i) {
        if(streamers[i]>2000) {
            cnt++;
        }
    }

    if((cnt*2)>=(n-1)) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
    return 0;
}