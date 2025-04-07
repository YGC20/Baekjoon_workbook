#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N, i, j;
    cin >> N;
    vector<int> A(N);
    for(i=0; i<N; ++i)
        cin >> A[i];
    vector<int> LIS(N, 1), LDS(N, 1);
    for(i=0; i<N; ++i)
        for(j=0; j<i; ++j)
            if(A[j]<A[i])
                LIS[i]=(LIS[i]>(LIS[j]+1))?LIS[i]:LIS[j]+1;
    for(i=N-1; i>=0; --i)
        for(j=N-1; j>i; --j)
            if(A[j]<A[i])
                LDS[i]=(LDS[i]>(LDS[j]+1))?LDS[i]:LDS[j]+1;
    int maxLen=0;
    for(i=0; i<N; ++i)
        maxLen = (maxLen>(LDS[i]+LIS[i]-1))?maxLen:(LDS[i]+LIS[i]-1);
    cout << maxLen << endl;
    return 0;
}