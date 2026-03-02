#include <iostream>
#include <vector>

using namespace std;

void solution(int test_set, int idx)
{   
    vector<int> route;
    while(idx>1) {
        route.push_back(idx);
        idx/=2;
    }
    int p = 1, q = 1;
    for(int i=route.size()-1; i>=0; --i) {
        if(route[i]%2==0) {
            q = p+q;
        }
        else {
            p = p+q;
        }
    }
    cout<<test_set<<" "<<p<<"/"<<q<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    if(cin>>test_case) {
        vector<vector<int>> graph;
        graph.push_back({1,1});
        for(int i=0; i<test_case; ++i) {
            int test_set, idx;
            cin>>test_set>>idx;
            solution(test_set, idx);
        }
    }
    return 0;
}