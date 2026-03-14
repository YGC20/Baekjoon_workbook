#include <iostream>
#include <vector>
using namespace std;

void solution(int n, vector<int>& t);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(cin>>n) {
        vector<int> tang(n);
        for(int i=0; i<n; ++i) {
            cin>>tang[i];
        }

        solution(n,tang);
    }
    return 0;
}

void solution(int n, vector<int>& t)
{
    vector<int> counter(10,0);
    int left = 0, max_len = 0, cnt = 0;

    for(int right = 0; right<n; ++right) {
        if(counter[t[right]]==0) {
            cnt++;
        }
        counter[t[right]]++;

        while(cnt>2) {
            counter[t[left]]--;
            if(counter[t[left]]==0) {
                cnt--;
            }
            left++;
        }

        max_len = (max_len>(right-left+1))?max_len:(right-left+1);
    }

    cout<<max_len<<"\n";
}