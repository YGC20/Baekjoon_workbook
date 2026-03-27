#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int k)
{
    vector<int> num;
    for(int i=1; i*i<=n; ++i) {
        if(n%i==0) {
            num.push_back(i);
            if(n!=(i*i)) {
                num.push_back(n/i);
            }
        }
    }
    sort(num.begin(), num.end());
    if(k>num.size()) {
        return 0;
    }
    return num[k-1];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    cout<<solution(n,k)<<"\n";

    return 0;
}