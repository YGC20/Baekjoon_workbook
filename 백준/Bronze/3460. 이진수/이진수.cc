#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n)
{
    vector<int> num;
    while(n!=1) {
        num.push_back(n%2);
        n/=2;
    }
    num.push_back(n);

    vector<int> idx;
    for(int i=0; i<num.size(); ++i) {
        if(num[i]==1) {
            idx.push_back(i);
        }
    }
    return idx;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    cin>>test_case;
    for(int i=0; i<test_case; ++i) {
        int n;
        cin>>n;
        vector<int> result = solution(n);
        for(int r : result) {
            cout<<r<<" ";
        }cout<<"\n";
    }

    return 0;
}