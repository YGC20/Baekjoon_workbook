#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, K; cin>>N>>K;
    vector<int> A(N);
    for(int i=0; i<N; ++i) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    cout<<A[K-1]<<"\n";
    return 0;
}