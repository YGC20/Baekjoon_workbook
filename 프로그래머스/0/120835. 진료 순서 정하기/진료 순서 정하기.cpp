#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Emer {
    int val, idx, pro;
};

bool compareByVal(const Emer& a, const Emer& b) {
    return a.val > b.val;
}

bool compareByIdx(const Emer& a, const Emer& b) {
    return a.idx < b.idx;
}

vector<int> solution(vector<int> emergency) {
    int len = emergency.size();
    vector<Emer> emerChart(len);
    for(int i=0; i<len; i++) {
        emerChart[i].val = emergency[i];
        emerChart[i].idx = i;
        emerChart[i].pro = 0;
    }
    
    sort(emerChart.begin(), emerChart.end(), compareByVal);
    for(int i=0; i<len; i++)
        emerChart[i].pro = i+1;
    
    sort(emerChart.begin(), emerChart.end(), compareByIdx);
    vector<int> result(len);
    for(int i=0; i<len; i++)
        result[i] = emerChart[i].pro;
    return result;
}