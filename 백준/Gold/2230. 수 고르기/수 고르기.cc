#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, m; cin>>n>>m;
    vector<ll> A(n);
    for(ll i=0; i<n; ++i) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    
    int left = 0, right = 0;
    ll result = 2000000001;
    while(right<n && left<=right) {
        ll sub = A[right]-A[left];
        if(sub>=m) {
            result = min(result, sub);
            left++;
            if(left>right && right<n) right++;
        }
        else {
            right++;
        }
    }
    cout<<result<<"\n";
    return 0;
}