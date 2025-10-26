#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for(const string &opr:operations){
        istringstream iss(opr);
        string cmd;
        int val;
        iss>>cmd>>val;
        if(cmd=="I")
            ms.insert(val);
        else if(!ms.empty()){
            if(val>0)
                ms.erase(prev(ms.end()));
            else
                ms.erase(ms.begin());
        }
    }
    if(ms.empty()) return {0,0};
    return {*ms.rbegin(),*ms.begin()};
}