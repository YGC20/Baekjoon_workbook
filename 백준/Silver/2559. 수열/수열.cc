#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k; cin>>n>>k;
    vector<int> days(n,0);
    for(int i=0; i<n; ++i) {
        cin>>days[i];
    }

    int sum = 0;
    for(int i=0; i<k; ++i) {
        sum += days[i];
    }
    
    int max = sum;
    int left = 0, right = k;
    while(right<n) {
        sum+=days[right++];
        sum-=days[left++];
        if(max<sum) max = sum;
    }

    cout<<max<<"\n";
    return 0;
}